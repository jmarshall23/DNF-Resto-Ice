set(PROJECT_NAME dnGame)

################################################################################
# Source groups
################################################################################
set(Classes
    "Classes/CardGame.uc"
    "Classes/dnBreakableGlass.uc"
    "Classes/dnDriveableMotorcycle.uc"
    "Classes/dnGlassFragments.uc"
    "Classes/dnVegasJackpotCounter.uc"
    "Classes/DynamicAmbientSound.uc"
    "Classes/PivotJoint.uc"
    "Classes/PuppetMimic.uc"
    "Classes/PuppetReach.uc"
    "Classes/PuppetStretch.uc"
    "Classes/VideoPoker.uc"
)
source_group("Classes" FILES ${Classes})

set(Classes__Ammo
    "Classes/ChainsawFuel.uc"
    "Classes/ChainsawFuel_Dirty.uc"
    "Classes/FreezerAmmo.uc"
    "Classes/HypoAir.uc"
    "Classes/HypoVial_Antidote.uc"
    "Classes/HypoVial_Antidote_Side.uc"
    "Classes/HypoVial_Health.uc"
    "Classes/HypoVial_Health_Side.uc"
    "Classes/HypoVial_Steroids.uc"
    "Classes/HypoVial_Steroids_Side.uc"
    "Classes/M16Clip.uc"
    "Classes/M16GAmmo.uc"
    "Classes/MightyFootAmmo.uc"
    "Classes/MultiBombAmmo.uc"
    "Classes/NukeCannister.uc"
    "Classes/PistolClip.uc"
    "Classes/PistolClip_Gold.uc"
    "Classes/PistolClipAP.uc"
    "Classes/PistolClipAP_Gold.uc"
    "Classes/PistolClipHP.uc"
    "Classes/PistolClipHP_Gold.uc"
    "Classes/RocketPack.uc"
    "Classes/RocketPackB.uc"
    "Classes/ShieldedLaserMine.uc"
    "Classes/ShotgunAmmo.uc"
    "Classes/ShotgunAmmo_Open.uc"
    "Classes/ShotgunAmmoAcid.uc"
    "Classes/ShotgunAmmoAcid_Open.uc"
    "Classes/ShrinkAmmo.uc"
    "Classes/SnatcherFaceAmmo.uc"
    "Classes/SniperCell.uc"
    "Classes/TripMineAmmo.uc"
)
source_group("Classes\\Ammo" FILES ${Classes__Ammo})

set(Classes__Chunks_and_Carcass
    "Classes/Chunk_EyeballA.uc"
    "Classes/Chunk_FleshA.uc"
    "Classes/Chunk_FleshB.uc"
    "Classes/Chunk_FleshC.uc"
    "Classes/Chunk_HandA.uc"
    "Classes/Chunk_Head.uc"
    "Classes/Chunk_OrganA.uc"
    "Classes/Chunk_TorsoA.uc"
    "Classes/CreatureChunks.uc"
    "Classes/CreaturePawnCarcass.uc"
    "Classes/dnCarcass.uc"
    "Classes/DukeMasterChunk.uc"
    "Classes/DukePlayerCarcass.uc"
    "Classes/HumanMeshChunk.uc"
    "Classes/HumanPawnCarcass.uc"
    "Classes/MasterCreatureChunk.uc"
    "Classes/PlayerChunks.uc"
    "Classes/RobotMasterChunk.uc"
    "Classes/RobotMeshChunk.uc"
    "Classes/RobotPawnCarcass.uc"
    "Classes/SnatcherMasterChunk.uc"
)
source_group("Classes\\Chunks and Carcass" FILES ${Classes__Chunks_and_Carcass})

set(Classes__DamageTypes
    "Classes/BiteDamage.uc"
    "Classes/CannonDamage.uc"
    "Classes/ChainsawDamage.uc"
    "Classes/EMPDamage.uc"
    "Classes/ExplosionChainDamage.uc"
    "Classes/FirewallDamage.uc"
    "Classes/FlamethrowerDamage.uc"
    "Classes/FreezeDamage.uc"
    "Classes/GrenadeDamage.uc"
    "Classes/HypoGunDamage.uc"
    "Classes/LaserMineDamage.uc"
    "Classes/M16Damage.uc"
    "Classes/MachinegunTurretDamage.uc"
    "Classes/MightyFootDamage.uc"
    "Classes/PipeBombDamage.uc"
    "Classes/PistolDamage.uc"
    "Classes/RocketDamage.uc"
    "Classes/ShotgunDamage.uc"
    "Classes/ShrinkDamage.uc"
    "Classes/SnatcherDeLeggedDamage.uc"
    "Classes/SnatcherDeLeggedLDamage.uc"
    "Classes/SnatcherDeLeggedRDamage.uc"
    "Classes/SnatcherFaceDamage.uc"
    "Classes/SnatcherRollDamage.uc"
    "Classes/SniperLaserDamage.uc"
    "Classes/StickyBombDamage.uc"
)
source_group("Classes\\DamageTypes" FILES ${Classes__DamageTypes})

set(Classes__Dancing_Game
    "Classes/DDD_Controls.uc"
    "Classes/DDD_DancerControl.uc"
    "Classes/DDD_Dispatcher.uc"
    "Classes/DDD_InputControl.uc"
)
source_group("Classes\\Dancing Game" FILES ${Classes__Dancing_Game})

set(Classes__Deathmatch
    "Classes/dnDeathmatchGame.uc"
    "Classes/dnDeathmatchGameReplicationInfo.uc"
    "Classes/dnRespawnMarker.uc"
)
source_group("Classes\\Deathmatch" FILES ${Classes__Deathmatch})

set(Classes__Deathmatch__Bughunt_Classes
    "Classes/BUG_209_Player.uc"
    "Classes/BUG_AttackDog_Player.uc"
    "Classes/BUG_Captain_Player.uc"
    "Classes/BUG_Flamer_Player.uc"
    "Classes/BUG_Freezer_Player.uc"
    "Classes/BUG_Grunt_Player.uc"
    "Classes/BUG_Octabrain_Player.uc"
    "Classes/BUG_Sapper_Player.uc"
    "Classes/BUG_Sniper_Player.uc"
    "Classes/BUG_Soldier_Player.uc"
    "Classes/EDF_209_Player.uc"
    "Classes/EDF_AttackDog_Player.uc"
    "Classes/EDF_Captain_Player.uc"
    "Classes/EDF_Flamer_Player.uc"
    "Classes/EDF_Freezer_Player.uc"
    "Classes/EDF_Grunt_Player.uc"
    "Classes/EDF_Sapper_Player.uc"
    "Classes/EDF_Sniper_Player.uc"
    "Classes/EDF_Soldier_Player.uc"
    "Classes/OctaPlayer.uc"
)
source_group("Classes\\Deathmatch\\Bughunt Classes" FILES ${Classes__Deathmatch__Bughunt_Classes})

set(Classes__Deathmatch__DM_HUD
    "Classes/dnDeathmatchGameHUD.uc"
    "Classes/dnTeamGameHUD.uc"
)
source_group("Classes\\Deathmatch\\DM HUD" FILES ${Classes__Deathmatch__DM_HUD})

set(Classes__Deathmatch__Messages
    "Classes/dnBombMessage.uc"
    "Classes/dnDeathmatchMessage.uc"
    "Classes/dnDeathMessage.uc"
    "Classes/dnFirstBloodMessage.uc"
    "Classes/dnKillerMessage.uc"
    "Classes/dnPrivateMessage.uc"
    "Classes/dnSayMessage.uc"
    "Classes/dnTeamGameMessage.uc"
    "Classes/dnVictimMessage.uc"
    "Classes/LightShadows.uc"
)
source_group("Classes\\Deathmatch\\Messages" FILES ${Classes__Deathmatch__Messages})

set(Classes__Deathmatch__Scoreboards
    "Classes/dnDeathmatchGameScoreboard.uc"
    "Classes/dnTeamGameScoreboard.uc"
)
source_group("Classes\\Deathmatch\\Scoreboards" FILES ${Classes__Deathmatch__Scoreboards})

set(Classes__Deathmatch__Team
    "Classes/dnTeamGame.uc"
    "Classes/dnTeamGame_Bomb.uc"
    "Classes/dnTeamGame_LMS.uc"
    "Classes/dnTeamInfo.uc"
)
source_group("Classes\\Deathmatch\\Team" FILES ${Classes__Deathmatch__Team})

set(Classes__Decorations
    "Classes/AmmoCase.uc"
    "Classes/Barrel.uc"
    "Classes/BlueBook.uc"
    "Classes/Book.uc"
    "Classes/Boulder.uc"
    "Classes/dnBall.uc"
    "Classes/dnBoneRope.uc"
    "Classes/dnDecoration.uc"
    "Classes/dnDecorationBigFrag.uc"
    "Classes/dnDecorationTrigger.uc"
    "Classes/dnDriveableDecoration.uc"
    "Classes/dnDriveableDecorationTrigger.uc"
    "Classes/dnLight.uc"
    "Classes/dnLight_FlashlightAmbient.uc"
    "Classes/dnLight_FlashlightBeam.uc"
    "Classes/dnPinBall.uc"
    "Classes/dnPinballBumper.uc"
    "Classes/dnPinBallTable.uc"
    "Classes/dnPoolBall.uc"
    "Classes/dnSwitchDecoration.uc"
    "Classes/dnThirdPersonShield.uc"
    "Classes/dnThirdPersonShieldBroken.uc"
    "Classes/G_Flashlight.uc"
    "Classes/G_FlashlightOff.uc"
    "Classes/JetpackAccessory.uc"
    "Classes/MountableDecoration.uc"
    "Classes/PlantedBomb.uc"
    "Classes/SlotMachineBank.uc"
    "Classes/StretchCable.uc"
)
source_group("Classes\\Decorations" FILES ${Classes__Decorations})

set(Classes__Effects
    "Classes/AnimSpriteEffect.uc"
    "Classes/BoneStretchEffect.uc"
    "Classes/BreakingGlass.uc"
    "Classes/Bubble1.uc"
    "Classes/BulletWhiz.uc"
    "Classes/CannonFlash.uc"
    "Classes/CannonFlash2.uc"
    "Classes/DecalBomb.uc"
    "Classes/dnAlienBloodHit.uc"
    "Classes/dnAlienBloodPool.uc"
    "Classes/dnAlienBloodSplat.uc"
    "Classes/dnBloodHit.uc"
    "Classes/dnBloodPool.uc"
    "Classes/dnBloodSplat.uc"
    "Classes/dnFlameThrowerFX_NozzleFlame.uc"
    "Classes/dnFlameThrowerFX_Shrunk_NozzleFlame.uc"
    "Classes/dnFragment.uc"
    "Classes/dnFreezeRayFX_MainStream.uc"
    "Classes/dnFreezeRayFX_NozzleMist.uc"
    "Classes/dnFreezeRayFX_NozzleStream.uc"
    "Classes/dnFXSpawner.uc"
    "Classes/dnLaserBeam.uc"
    "Classes/dnLight_ProtonMonitor.uc"
    "Classes/dnMeshImmolation.uc"
    "Classes/dnOilHit.uc"
    "Classes/dnOilPool.uc"
    "Classes/dnOilSplat.uc"
    "Classes/dnPawnFreeze.uc"
    "Classes/dnPawnImmolation.uc"
    "Classes/dnPawnImmolation_AlienPig.uc"
    "Classes/dnPawnImmolation_EDFDog.uc"
    "Classes/dnPawnImmolation_Octabrain.uc"
    "Classes/dnPawnImmolation_PodProtector.uc"
    "Classes/dnPawnShrink.uc"
    "Classes/dnWeaponFX.uc"
    "Classes/dnWeaponFX_EMPSphere.uc"
    "Classes/dnWeaponFX_IceNukeSphere.uc"
    "Classes/dnWeaponFX_NukeFire.uc"
    "Classes/dnWeaponFX_NukeSphere.uc"
    "Classes/dnWeaponFX_RPGFire.uc"
    "Classes/EMPulse.uc"
    "Classes/ExplodingWall.uc"
    "Classes/ExplosionChain.uc"
    "Classes/EyeBlinkEffect.uc"
    "Classes/FlamethrowerCollisionActor.uc"
    "Classes/FlamethrowerCollisionActorShrunk.uc"
    "Classes/FlashEffects.uc"
    "Classes/FreezerCollisionActor.uc"
    "Classes/FrozenBlock.uc"
    "Classes/FrozenBlockBody.uc"
    "Classes/FrozenBlockLeftArm.uc"
    "Classes/FrozenBlockLegs.uc"
    "Classes/FrozenBlockRightArm.uc"
    "Classes/HeadBomb.uc"
    "Classes/LipSyncEffect.uc"
    "Classes/M16Flash.uc"
    "Classes/MimicRotationEffect.uc"
    "Classes/PistolFlash.uc"
    "Classes/Ricochet.uc"
    "Classes/robotdamagesmokea.uc"
    "Classes/RobotEye.uc"
    "Classes/ShotgunFlash.uc"
    "Classes/ShrinkRayBeamAnchor.uc"
    "Classes/SmokeGenerator.uc"
    "Classes/SniperPoint.uc"
    "Classes/SpriteSmokePuff.uc"
    "Classes/VertexMagnetEffect.uc"
)
source_group("Classes\\Effects" FILES ${Classes__Effects})

set(Classes__Funny_Stuff
    "Classes/DisembodiedHeadOfLincoln.uc"
    "Classes/InterplexingBeacon.uc"
)
source_group("Classes\\Funny Stuff" FILES ${Classes__Funny_Stuff})

set(Classes__HUD
    "Classes/DukeHUD.uc"
    "Classes/HUDIndexItem.uc"
    "Classes/HUDIndexItem_ActorHealth.uc"
    "Classes/HUDIndexItem_Air.uc"
    "Classes/HUDIndexItem_AltAmmo.uc"
    "Classes/HUDIndexItem_AltMultiAmmo.uc"
    "Classes/HUDIndexItem_Ammo.uc"
    "Classes/HUDIndexItem_Bomb.uc"
    "Classes/HUDIndexItem_Cash.uc"
    "Classes/HUDIndexItem_Chainsaw.uc"
    "Classes/HUDIndexItem_Credits.uc"
    "Classes/HUDIndexItem_DecoHealth.uc"
    "Classes/HUDIndexItem_DefuseBomb.uc"
    "Classes/HUDIndexItem_DMFrags.uc"
    "Classes/HUDIndexItem_EGO.uc"
    "Classes/HUDIndexItem_Energy.uc"
    "Classes/HUDIndexItem_Flamethrower.uc"
    "Classes/HUDIndexItem_FlamethrowerAlt.uc"
    "Classes/HUDIndexItem_Freezer.uc"
    "Classes/HUDIndexItem_FreezerAlt.uc"
    "Classes/HUDIndexItem_Hypo.uc"
    "Classes/HUDIndexItem_HypoAlt.uc"
    "Classes/HUDIndexItem_Jetpack.uc"
    "Classes/HUDIndexItem_M16Gun.uc"
    "Classes/HUDIndexItem_M16GunAlt.uc"
    "Classes/HUDIndexItem_MultiBomb.uc"
    "Classes/HUDIndexItem_MultiBombAlt.uc"
    "Classes/HUDIndexItem_Pistol.uc"
    "Classes/HUDIndexItem_PistolAlt.uc"
    "Classes/HUDIndexItem_Prompt.uc"
    "Classes/HUDIndexItem_RiotShield.uc"
    "Classes/HUDIndexItem_RPG.uc"
    "Classes/HUDIndexItem_RPGAlt.uc"
    "Classes/HUDIndexItem_Shotgun.uc"
    "Classes/HUDIndexItem_ShotgunAlt.uc"
    "Classes/HUDIndexItem_ShrinkRay.uc"
    "Classes/HUDIndexItem_ShrinkRayAlt.uc"
    "Classes/HUDIndexItem_Sniper.uc"
    "Classes/HUDIndexItem_SniperAlt.uc"
    "Classes/HUDIndexItem_TripMine.uc"
    "Classes/HUDIndexItem_TripMineAlt.uc"
    "Classes/HUDIndexItem_WeaponAltAmmo.uc"
    "Classes/HUDIndexItem_WeaponAmmo.uc"
)
source_group("Classes\\HUD" FILES ${Classes__HUD})

set(Classes__HitPackages
    "Classes/HitPackage_AlienFlesh.uc"
    "Classes/HitPackage_DukeLevel.uc"
    "Classes/HitPackage_Flesh.uc"
    "Classes/HitPackage_Shield.uc"
    "Classes/HitPackage_ShieldBig.uc"
    "Classes/HitPackage_ShieldHeld.uc"
    "Classes/HitPackage_Shotgun.uc"
    "Classes/HitPackage_Steel.uc"
)
source_group("Classes\\HitPackages" FILES ${Classes__HitPackages})

set(Classes__Info
    "Classes/CameraManager.uc"
    "Classes/CreatureTasks.uc"
    "Classes/dnFontInfo.uc"
    "Classes/dnSinglePlayer.uc"
    "Classes/dnSinglePlayer_NoPistol.uc"
    "Classes/FearSpot.uc"
    "Classes/NPCAlertBeacon.uc"
    "Classes/TaskInfo.uc"
)
source_group("Classes\\Info" FILES ${Classes__Info})

set(Classes__InputDecorations
    "Classes/AccessPad.uc"
    "Classes/AccessPad_Desk.uc"
    "Classes/dnEmailSystem.uc"
    "Classes/dnEmailSystemPrefab_Wall.uc"
    "Classes/dnKeyboardInput.uc"
    "Classes/ezAbsolv.uc"
    "Classes/EZPhone.uc"
    "Classes/EZPhone_Desk.uc"
    "Classes/EZPhoneEvent.uc"
    "Classes/EZPhoneTrigger.uc"
    "Classes/EZVendMachine.uc"
    "Classes/EZVendMachine_Dirty.uc"
    "Classes/InputDecoration.uc"
    "Classes/InputDecorationTrigger.uc"
    "Classes/InversePuzzle.uc"
    "Classes/InversePuzzle_Desk.uc"
    "Classes/KeyPad.uc"
    "Classes/PowerPuzzle.uc"
    "Classes/PowerPuzzle_Desk.uc"
)
source_group("Classes\\InputDecorations" FILES ${Classes__InputDecorations})

set(Classes__Inventory
    "Classes/Bomb.uc"
    "Classes/DollarSingle.uc"
    "Classes/DollarWad.uc"
    "Classes/DollarWad_Five.uc"
    "Classes/DollarWad_Hundred.uc"
    "Classes/DollarWad_Three.uc"
    "Classes/DollarWad_TwentyFive.uc"
    "Classes/DukeHand.uc"
    "Classes/HoloDuke.uc"
    "Classes/Jetpack.uc"
    "Classes/Keycard.uc"
    "Classes/MedKit.uc"
    "Classes/Money.uc"
    "Classes/PowerCell.uc"
    "Classes/Rebreather.uc"
    "Classes/RiotShield.uc"
    "Classes/Steroids.uc"
    "Classes/ToDoList.uc"
    "Classes/Upgrade_EMP.uc"
    "Classes/Upgrade_HeatVision.uc"
    "Classes/Upgrade_NightVision.uc"
    "Classes/Upgrade_ZoomMode.uc"
    "Classes/VendSnack.uc"
)
source_group("Classes\\Inventory" FILES ${Classes__Inventory})

set(Classes__Life
    "Classes/Life.uc"
    "Classes/LifeCell.uc"
    "Classes/LifeDetector.uc"
    "Classes/LifeGrid.uc"
    "Classes/LifeGridAssign.uc"
)
source_group("Classes\\Life" FILES ${Classes__Life})

set(Classes__Movers
    "Classes/ElevatorMover.uc"
    "Classes/RotatingMover.uc"
    "Classes/SwayMover.uc"
)
source_group("Classes\\Movers" FILES ${Classes__Movers})

set(Classes__Mutators
    "Classes/BiggerHead.uc"
    "Classes/BigHead.uc"
    "Classes/EMPMutator.uc"
    "Classes/HeatVisionMutator.uc"
    "Classes/Jetpacks.uc"
    "Classes/LowGrav.uc"
    "Classes/NightVisionMutator.uc"
    "Classes/ZoomModeMutator.uc"
)
source_group("Classes\\Mutators" FILES ${Classes__Mutators})

set(Classes__Navigation
    "Classes/Transporter.uc"
    "Classes/WaterZone.uc"
)
source_group("Classes\\Navigation" FILES ${Classes__Navigation})

set(Classes__Pawns
    "Classes/DukePlayer.uc"
)
source_group("Classes\\Pawns" FILES ${Classes__Pawns})

set(Classes__Projectiles
    "Classes/BubbleTrail.uc"
    "Classes/CloakedLaserMine.uc"
    "Classes/dnGrenade.uc"
    "Classes/dnGrenadeShrunk.uc"
    "Classes/dnHomingRocket.uc"
    "Classes/dnHomingTorpedo.uc"
    "Classes/dnNuke.uc"
    "Classes/dnNukeShrunk.uc"
    "Classes/dnParachuteBomb.uc"
    "Classes/dnProjectile.uc"
    "Classes/dnRocket.uc"
    "Classes/dnRocket_BrainBlast.uc"
    "Classes/dnRocket_ShrinkBlast.uc"
    "Classes/dnRocketShrunk.uc"
    "Classes/dnTossedGrenade.uc"
    "Classes/EDFRocket.uc"
    "Classes/ExpanderPulse.uc"
    "Classes/FireWallBomb.uc"
    "Classes/FireWallBombShrunk.uc"
    "Classes/FireWallCruiser.uc"
    "Classes/FireWallCruiserShrunk.uc"
    "Classes/FireWallStarter.uc"
    "Classes/FireWallStarterScorch.uc"
    "Classes/FireWallStarterShrunk.uc"
    "Classes/IceNuke.uc"
    "Classes/LaserMine.uc"
    "Classes/PipeBomb.uc"
    "Classes/PipeBombShrunk.uc"
    "Classes/RoamingLaserMine.uc"
    "Classes/ShockWave.uc"
    "Classes/ShotgunShell.uc"
    "Classes/StickyBomb.uc"
    "Classes/StickyBombShrunk.uc"
)
source_group("Classes\\Projectiles" FILES ${Classes__Projectiles})

set(Classes__Rain
    "Classes/RainPuddleTrigger.uc"
    "Classes/RainTrigger.uc"
)
source_group("Classes\\Rain" FILES ${Classes__Rain})

set(Classes__Triggers
    "Classes/AddEmailTrigger.uc"
    "Classes/BombPlacementTrigger.uc"
    "Classes/DecoDamageTrigger.uc"
    "Classes/dnBreakableGlassTrigger.uc"
    "Classes/DoorMoverTrigger.uc"
    "Classes/DOTTrigger_Fire.uc"
    "Classes/Earthquake.uc"
    "Classes/ElevatorTrigger.uc"
    "Classes/HealthActor.uc"
    "Classes/LeverControl1.uc"
    "Classes/MeshMultiplexer.uc"
    "Classes/NewLocationTrigger.uc"
    "Classes/ObjectiveTrigger.uc"
    "Classes/PlaneRollDispatch.uc"
    "Classes/PushButtonControl1.uc"
    "Classes/RandomSpawn.uc"
    "Classes/SOSTrigger.uc"
    "Classes/StochasticTrigger.uc"
    "Classes/TriggerCrane.uc"
    "Classes/TriggerDamage.uc"
    "Classes/TriggerDnProjectileSpawn.uc"
    "Classes/TriggeredDeath.uc"
    "Classes/TriggerEgo.uc"
    "Classes/TriggerLight.uc"
    "Classes/TriggerPinballBumper.uc"
    "Classes/TriggerPlayer.uc"
    "Classes/TriggerSlotMachineBank.uc"
    "Classes/TriggerUntrigger.uc"
    "Classes/TriggerVideoPoker.uc"
    "Classes/TriggerVideoPoker2.uc"
)
source_group("Classes\\Triggers" FILES ${Classes__Triggers})

set(Classes__Turrets
    "Classes/ControllableTurret.uc"
    "Classes/ControllableTurret_Cannon.uc"
    "Classes/ControllableTurret_CannonB.uc"
    "Classes/ControllableTurret_CannonBNS.uc"
    "Classes/ControllableTurret_CannonNS.uc"
    "Classes/ControllableTurret_MachineGun.uc"
    "Classes/CTViewActor.uc"
    "Classes/ModifyTurretTrigger.uc"
    "Classes/MoveBetweenLikeTurrets.uc"
)
source_group("Classes\\Turrets" FILES ${Classes__Turrets})

set(Classes__Voice
    "Classes/dnVoicePack.uc"
    "Classes/FemalePlayerSounds.uc"
    "Classes/MalePlayerSounds.uc"
    "Classes/PigcopPlayerSounds.uc"
)
source_group("Classes\\Voice" FILES ${Classes__Voice})

set(Classes__Weapons
    "Classes/dnWeapon.uc"
    "Classes/dnWeaponNoMesh.uc"
    "Classes/dnWeaponNoMesh_Pistol.uc"
    "Classes/DukeChainsaw.uc"
    "Classes/Flamethrower.uc"
    "Classes/Freezer.uc"
    "Classes/HypoGun.uc"
    "Classes/M16.uc"
    "Classes/MeleeWeapon.uc"
    "Classes/MightyFoot.uc"
    "Classes/MultiBomb.uc"
    "Classes/OctaBlaster.uc"
    "Classes/Pistol.uc"
    "Classes/Pistol_Gold.uc"
    "Classes/RPG.uc"
    "Classes/Shotgun.uc"
    "Classes/Shrinkray.uc"
    "Classes/SnatcherFace.uc"
    "Classes/SniperRifle.uc"
    "Classes/TripMine.uc"
)
source_group("Classes\\Weapons" FILES ${Classes__Weapons})

set(ALL_FILES
    ${Classes}
    ${Classes__Ammo}
    ${Classes__Chunks_and_Carcass}
    ${Classes__DamageTypes}
    ${Classes__Dancing_Game}
    ${Classes__Deathmatch}
    ${Classes__Deathmatch__Bughunt_Classes}
    ${Classes__Deathmatch__DM_HUD}
    ${Classes__Deathmatch__Messages}
    ${Classes__Deathmatch__Scoreboards}
    ${Classes__Deathmatch__Team}
    ${Classes__Decorations}
    ${Classes__Effects}
    ${Classes__Funny_Stuff}
    ${Classes__HUD}
    ${Classes__HitPackages}
    ${Classes__Info}
    ${Classes__InputDecorations}
    ${Classes__Inventory}
    ${Classes__Life}
    ${Classes__Movers}
    ${Classes__Mutators}
    ${Classes__Navigation}
    ${Classes__Pawns}
    ${Classes__Projectiles}
    ${Classes__Rain}
    ${Classes__Triggers}
    ${Classes__Turrets}
    ${Classes__Voice}
    ${Classes__Weapons}
)

add_custom_target(${PROJECT_NAME} SOURCES ${ALL_FILES})

