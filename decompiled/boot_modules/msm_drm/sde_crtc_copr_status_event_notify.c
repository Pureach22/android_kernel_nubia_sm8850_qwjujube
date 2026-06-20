__int64 __fastcall sde_crtc_copr_status_event_notify(__int64 result)
{
  _QWORD *v1; // x19
  __int64 v2; // x0
  __int64 v3; // [xsp+8h] [xbp-38h] BYREF
  _QWORD v4[6]; // [xsp+10h] [xbp-30h] BYREF

  v4[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)(result + 7947) == 1 )
  {
    v1 = (_QWORD *)result;
    v2 = *(_QWORD *)(result + 2216);
    v3 = 0x2880000013LL;
    memset(v4, 0, 40);
    if ( (unsigned int)sde_dspp_copr_read_status(v2, v4) )
      result = printk(&unk_2159CA, "sde_crtc_copr_status_event_notify");
    else
      result = msm_mode_object_event_notify(v1 + 14, *v1, &v3, v4);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
