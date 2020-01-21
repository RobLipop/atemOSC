/* -LICENSE-START-
 ** Copyright (c) 2011 Blackmagic Design
 **
 ** Permission is hereby granted, free of charge, to any person or organization
 ** obtaining a copy of the software and accompanying documentation covered by
 ** this license (the "Software") to use, reproduce, display, distribute,
 ** execute, and transmit the Software, and to prepare derivative works of the
 ** Software, and to permit third-parties to whom the Software is furnished to
 ** do so, all subject to the following:
 **
 ** The copyright notices in the Software and this entire statement, including
 ** the above license grant, this restriction and the following disclaimer,
 ** must be included in all copies of the Software, in whole or in part, and
 ** all derivative works of the Software, unless such copies or derivative
 ** works are solely in the form of machine-executable object code generated by
 ** a source language processor.
 **
 ** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 ** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 ** FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 ** SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 ** FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 ** ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 ** DEALINGS IN THE SOFTWARE.
 ** -LICENSE-END-
 */

#import "BMDSwitcherAPI.h"
#import "VVOSC/VVOSC.h"
#import <vector>
#import <map>

#import <Cocoa/Cocoa.h>

#import "FeedbackMonitors.h"
#import "OSCEndpoint.h"

@class OSCAddressPanel;
@class OSCReceiver;

@interface AppDelegate : NSObject <NSApplicationDelegate>
{
	NSWindow *window;
	
	IBMDSwitcherDiscovery*		        mSwitcherDiscovery;
	IBMDSwitcherKeyFlyParameters*	    mDVEControl;
	SwitcherMonitor*			        mSwitcherMonitor;
	DownstreamKeyerMonitor*             mDownstreamKeyerMonitor;
	UpstreamKeyerMonitor*               mUpstreamKeyerMonitor;
	UpstreamKeyerLumaParametersMonitor* mUpstreamKeyerLumaParametersMonitor;
	UpstreamKeyerChromaParametersMonitor* mUpstreamKeyerChromaParametersMonitor;
	TransitionParametersMonitor*        mTransitionParametersMonitor;
	MacroPoolMonitor*       			mMacroPoolMonitor;
	std::vector<SendStatusInterface*>   mMonitors;
	
	OSCReceiver*                mOscReceiver;
	OSCManager*					manager;
	
	IBOutlet OSCAddressPanel*   helpPanel;
	IBOutlet NSTextView*        logTextView;
}

@property (readonly)       IBMDSwitcher*				        	mSwitcher;
@property (readonly)       std::vector<IBMDSwitcherSuperSourceBox*> mSuperSourceBoxes;
@property (readonly)       std::map<BMDSwitcherInputId, IBMDSwitcherInput*> mInputs;
@property (readonly)       std::map<BMDSwitcherInputId, InputMonitor*> mInputMonitors;
@property (readonly)       std::map<BMDSwitcherHyperDeckId, IBMDSwitcherHyperDeck*> mHyperdecks;
@property (readonly)       std::map<BMDSwitcherHyperDeckId, HyperDeckMonitor*> mHyperdeckMonitors;
@property (readonly)       std::vector<IBMDSwitcherInputAux*>       mSwitcherInputAuxList;
@property (readonly)       IBMDSwitcherStills*                      mStills;
@property (readonly)       IBMDSwitcherInputSuperSource*            mSuperSource;
@property (readonly)       IBMDSwitcherMacroPool*                   mMacroPool;
@property (readonly)       IBMDSwitcherMacroControl*                mMacroControl;
@property (assign, readonly) OSCInPort*                             inPort;
@property (assign, readonly) OSCOutPort*                            outPort;
@property (readonly)       std::vector<IBMDSwitcherMediaPlayer*>    mMediaPlayers;
@property (readonly)       IBMDSwitcherMediaPool*                   mMediaPool;
@property (readonly)       std::vector<IBMDSwitcherKey*>            keyers;
@property (readonly)       std::vector<IBMDSwitcherDownstreamKey*>  dsk;
@property (readonly)       IBMDSwitcherTransitionParameters*        switcherTransitionParameters;
@property (readonly)       MixEffectBlockMonitor*                   mMixEffectBlockMonitor;
@property (readonly)       IBMDSwitcherMixEffectBlock*              mMixEffectBlock;
@property (readonly)       std::map<BMDSwitcherAudioInputId, IBMDSwitcherAudioInput*> mAudioInputs;
@property (readonly)       std::map<BMDSwitcherAudioInputId, AudioInputMonitor*> mAudioInputMonitors;
@property (readonly)       IBMDSwitcherAudioMixer*                  mAudioMixer;
@property (readonly)       AudioMixerMonitor*                       mAudioMixerMonitor;
@property (readonly)       bool                                     isConnectedToATEM;
@property (strong)         IBOutlet NSWindow*                       window;
@property (strong)         id                                       activity;

@property(nonatomic, retain) NSMutableArray<OSCEndpoint *> *endpoints;

- (void)connectBMD;
- (void)portChanged:(int)inPortValue out:(int)outPortValue ip:(NSString *)outIpStr;
- (IBAction)githubPageButtonPressed:(id)sender;

- (void)switcherConnected;
- (void)switcherDisconnected;

- (void)sendStatus;
- (void)sendEachStatus:(int)nextMonitor;

- (void)logMessage:(NSString *)message;

@end
