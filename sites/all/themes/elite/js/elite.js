var qelite_ww, qelite_wh, qelite_rw = 0;

function qelite_taketraining_btn() {
	if ( jQuery('body').hasClass('node-type-training') ) {
		jQuery('#quiz-start-quiz-button-form').submit();
	} else {
		jQuery('#wback').click();
	}
	return false;
}

function tblclub_agecheck() {
  var clubarangesel = jQuery('#edit-field-age-range-und');
  var arange = clubarangesel.children(':selected').html();
  var p18 = false;
  var p13 = false;
  if ( arange ) {
    if ( arange == '18+' ) {
      //console.log('18?');
      p18 = true;
    } else {
      if ( arange == '13 - 17' ) {
        //console.log('13+?');
        p13 = true;
      }
    }
  }
  if ( p18 ) {
    // show Teacher check + Last Name
    jQuery('.form-item-check-teacher, .field-name-field-user-name-last').show();
    // hide "no email" check and email description
    jQuery('.form-item-skip-email, .emailageclar').hide();
  } else {
    // hide Teacher check + Last Name
    jQuery('.form-item-check-teacher, .field-name-field-user-name-last').hide();
    // hide "no email" check and email description
    jQuery('.form-item-skip-email, .emailageclar').show();
    if ( p13 ) {
      jQuery('.underand').hide();
      jQuery('.ifover13and').show();
    } else {
      jQuery('.underand').show();
      jQuery('.ifover13and').hide();
    }
  }
}

(function ($) {
  Drupal.behaviors.qElite = {
    attach: function (context, settings) {
			// and then
			$(window).unbind('resize.qelite').bind('resize.qelite', function () {
				qelite_ww = $(window).width();
				qelite_wh = $(window).height();
				var qelite_widthchange = false;
				
				var nw = 320;
				if ( qelite_ww >= 1024 ) { //why
					nw = 1080;
				} else if ( qelite_ww >= 768 ) { 
					nw = 768;
				}
				if ( nw != qelite_rw ) {
					qelite_rw = nw;
					qelite_widthchange = true;
				}
				
				$("#qvideo").each(function() {
					var tw = $(this).parent().width();
					var th = Math.ceil(tw*9/16);
					$(this).attr({'width':tw,'height':th});
				});
				if ( $('#wslashd').size() > 0 ) {
					var ih = qelite_wh - ( $('body').hasClass('admin-menu') ? 20 : 0 ) - 54;
          //console.log('set wslashd iframe width '+ qelite_ww + ' height '+ ih);
					$('#wslashd iframe').attr('width', qelite_ww).attr('height',ih);
				}
				if ( $('#block-views-home-slides-block').size() > 0 ) {
					if ( qelite_widthchange ) {
						$('#block-views-home-slides-block .qimgs').each(function(i) {
							$(this).empty();
							$('<img />').attr({
								src: $(this).data('main-'+qelite_rw),
								title: $(this).parents('.views-field-field-image').siblings('.views-field-title').children().text(),
							}).css({
								width: '100%',
								height: 'auto',
							}).appendTo($(this));
						});
					}
				}
			}).trigger('resize.qelite');
			
			if ( $('#elite-user-flop').size() > 0 ) {
				$('#avatar-block-wrapper a').unbind('click.qelite').bind('click.qelite',function() {
					$('#block-elite-custom-userflop').slideToggle(100);
					return false;
				});
				if ( $('#elite-user-flop a.x').size() == 0 ) {
					$('<a href="#x" class="x">x</a>').click(function() {
						$('#block-elite-custom-userflop').slideUp(41);
						return false;
					}).appendTo('#elite-user-flop');
				}
			}
			// training details
			if ( $('body').hasClass('node-type-training') || $('body').hasClass('node-type-quiz') ) {
				var wslash = $('.field-name-field-wslash-training a');
				if ( wslash.size() > 0 ) {
					wslash.click(function() {
						var turl = $(this).attr('href');
						$("#section-header, #section-content, #section-footer").hide();
						var wc = $('<div />');
						wc.attr('id','wslashd').append('<div class="wbar"><a href="#back" id="wback">Back</a><a href="/" id="logo">Qualcomm Elite</a></div>');
						
						var wh = $(window).height() - ( $('body').hasClass('admin-menu') ? 20 : 0 ) - 54;
						
						var ifr = $('<iframe />');
            //console.log('creating iframe width '+ qelite_ww + ' height '+ wh);
						ifr.attr('src',turl).attr('width',qelite_ww).attr('height',wh);
						ifr.appendTo(wc);
						wc.appendTo('#page');
						
						$("#wback").click(function() {
							$('#section-header, #section-content, #section-footer').show();
							$('#wslashd').remove();
							return false;
						});
						
						return false;
					});
				}
				if ( $('body').hasClass('node-type-quiz') ) {
					$('.answertable .multichoice-icon.correct').each(function() {
						$(this).parent().attr('width','40').prev().find('tr.correct').append($(this).parent()).siblings().children().attr('colspan','2');
					});
				}
			}
			// trend article details
			if ( $('body').hasClass('node-type-article') ) {
				var extl = $('.field-name-field-external-link a');
				if ( extl.size() > 0 ) {
					var collectpts = $('.flag-collect-points a.flag-action');
					if ( collectpts.size() > 0 ) {
						collectpts.hide();
						extl.click(function() {
							collectpts.show();
						});
					}
				}
			}
			// tool details
			if ( $('body').hasClass('node-type-tool') ) {
				var tgal = $('.field-name-field-image');
				if ( !tgal.hasClass('gal') ) {
					if ( tgal.find('.field-item:first').addClass('onn').siblings().size() > 0 ) {
						// more than 1 img = arrow'd
						tgal.append('<a href="#" class="arr p"></a><a href="#" class="arr n"></a>').children('.arr').click(function() {
							var onn = $(this).siblings('.field-items').find('.onn');
							var nx = onn.next();
							if ( $(this).hasClass('p') ) {
								nx = onn.prev();
								if ( nx.size() == 0 ) {
									nx = onn.parent().children(':last');
								}
							} else {
								if ( nx.size() == 0 ) {
									nx = onn.parent().children(':first');
								}
							}
							onn.add(nx).toggleClass('onn');
							return false;
						});
					}
					tgal.addClass('gal');
				}
			}
      if ( $('#edit-field-age-range-und').size() > 0 ) {
        $('#edit-field-age-range-und').bind('change', tblclub_agecheck);
      }
		}
	};
})(jQuery);