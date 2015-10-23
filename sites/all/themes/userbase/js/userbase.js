var userbase_ww, userbase_wh, userbase_rw = 0;

function userbase_taketraining_btn() {
	if ( jQuery('body').hasClass('node-type-training') ) {
		jQuery('#quiz-start-quiz-button-form').submit();
	} else {
		jQuery('#wback').click();
	}
	return false;
}

(function ($) {
  Drupal.behaviors.userBase = {
    attach: function (context, settings) {
			// and then
			$(window).unbind('resize.userbase').bind('resize.userbase', function () {
				userbase_ww = $(window).width();
				userbase_wh = $(window).height();
				var userbase_widthchange = false;
				
				var nw = 320;
				if ( userbase_ww >= 1024 ) { //why
					nw = 1080;
				} else if ( userbase_ww >= 768 ) { 
					nw = 768;
				}
				if ( nw != userbase_rw ) {
					userbase_rw = nw;
					userbase_widthchange = true;
				}
				
				$("#qvideo").each(function() {
					var tw = $(this).parent().width();
					var th = Math.ceil(tw*9/16);
					$(this).attr({'width':tw,'height':th});
				});
				if ( $('#wslashd').size() > 0 ) {
					var ih = userbase_wh - ( $('body').hasClass('admin-menu') ? 20 : 0 ) - 54;
          //console.log('set wslashd iframe width '+ userbase_ww + ' height '+ ih);
					$('#wslashd iframe').attr('width', userbase_ww).attr('height',ih);
				}
				if ( $('#block-views-home-slides-block').size() > 0 ) {
					if ( userbase_widthchange ) {
						$('#block-views-home-slides-block .qimgs').each(function(i) {
							$(this).empty();
							$('<img />').attr({
								src: $(this).data('main-'+userbase_rw),
								title: $(this).parents('.views-field-field-image').siblings('.views-field-title').children().text(),
							}).css({
								width: '100%',
								height: 'auto',
							}).appendTo($(this));
						});
					}
				}
			}).trigger('resize.userbase');
			
			if ( $('#userbase-user-flop').size() > 0 ) {
				$('#avatar-block-wrapper a').unbind('click.userbase').bind('click.userbase',function() {
					$('#block-userbase-custom-userflop').slideToggle(100);
					return false;
				});
				if ( $('#userbase-user-flop a.x').size() == 0 ) {
					$('<a href="#x" class="x">x</a>').click(function() {
						$('#block-userbase-custom-userflop').slideUp(41);
						return false;
					}).appendTo('#userbase-user-flop');
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
						wc.attr('id','wslashd').append('<div class="wbar"><a href="#back" id="wback">Back</a><a href="/" id="logo"></a></div>');
						
						var wh = $(window).height() - ( $('body').hasClass('admin-menu') ? 20 : 0 ) - 54;
						
						var ifr = $('<iframe />');
            //console.log('creating iframe width '+ userbase_ww + ' height '+ wh);
						ifr.attr('src',turl).attr('width',userbase_ww).attr('height',wh);
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
		}
	};
})(jQuery);