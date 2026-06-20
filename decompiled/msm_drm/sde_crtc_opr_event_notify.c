__int64 __fastcall sde_crtc_opr_event_notify(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x0
  int v4; // w21
  unsigned int v10; // w8
  unsigned int v12; // w8
  unsigned int v14; // w8
  __int64 v15; // [xsp+8h] [xbp-18h] BYREF
  __int64 v16; // [xsp+10h] [xbp-10h] BYREF
  __int64 v17; // [xsp+18h] [xbp-8h] BYREF

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = 0;
  *(_DWORD *)(result + 7912) = 0;
  if ( !*(_DWORD *)(result + 2192) )
    goto LABEL_15;
  v1 = result;
  v2 = *(_QWORD *)(result + 2216);
  _X20 = (unsigned int *)(v1 + 7912);
  v15 = 0xC8000000FLL;
  result = ((__int64 (__fastcall *)(__int64, __int64 *))sde_dspp_spr_read_opr_value)(v2, &v16);
  if ( (_DWORD)result )
  {
    result = printk(&unk_23EFDE, "sde_crtc_opr_event_notify");
    v4 = 0;
  }
  else
  {
    __asm { PRFM            #0x11, [X20] }
    do
      v10 = __ldxr(_X20);
    while ( __stxr(v10 + 1, _X20) );
    if ( (_DWORD)v16 == *(_DWORD *)(v1 + 7916) )
    {
      v4 = 0;
    }
    else
    {
      v4 = 1;
      *(_DWORD *)(v1 + 7916) = v16;
    }
  }
  if ( *(_DWORD *)(v1 + 2192) < 2u )
    goto LABEL_13;
  result = ((__int64 (__fastcall *)(_QWORD, char *))sde_dspp_spr_read_opr_value)(
             *(_QWORD *)(v1 + 2264),
             (char *)&v16 + 4);
  if ( (_DWORD)result )
  {
    result = printk(&unk_23EFDE, "sde_crtc_opr_event_notify");
  }
  else
  {
    __asm { PRFM            #0x11, [X20] }
    do
      v12 = __ldxr(_X20);
    while ( __stxr(v12 + 1, _X20) );
    if ( HIDWORD(v16) != *(_DWORD *)(v1 + 7920) )
    {
      v4 = 1;
      *(_DWORD *)(v1 + 7920) = HIDWORD(v16);
    }
  }
  if ( *(_DWORD *)(v1 + 2192) < 3u )
  {
LABEL_13:
    if ( v4 )
      result = msm_mode_object_event_notify(v1 + 112, *(_QWORD *)v1, &v15, v1 + 7912);
LABEL_15:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( (unsigned int)((__int64 (__fastcall *)(_QWORD, __int64 *))sde_dspp_spr_read_opr_value)(
                       *(_QWORD *)(v1 + 2312),
                       &v17) )
  {
    result = printk(&unk_23EFDE, "sde_crtc_opr_event_notify");
    if ( *(_DWORD *)(v1 + 2192) > 3u )
      __break(0x5512u);
    goto LABEL_13;
  }
  __asm { PRFM            #0x11, [X20] }
  do
    v14 = __ldxr(_X20);
  while ( __stxr(v14 + 1, _X20) );
  __break(0x5512u);
  return sde_crtc_mdnie_art_event_notify();
}
