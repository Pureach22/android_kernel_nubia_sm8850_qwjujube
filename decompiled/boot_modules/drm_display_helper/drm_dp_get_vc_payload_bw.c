unsigned __int64 __fastcall drm_dp_get_vc_payload_bw(__int64 a1, int a2, int a3)
{
  unsigned int v6; // w21
  __int64 v7; // x8
  __int64 v8; // x1

  v6 = drm_dp_bw_channel_coding_efficiency(a2 > 999999);
  if ( !a2 || !a3 )
  {
    v7 = *(_QWORD *)(a1 + 104);
    if ( v7 )
      v8 = *(_QWORD *)(v7 + 8);
    else
      v8 = 0;
    _drm_dev_dbg(0, v8, 2, "invalid link rate/lane count: (%d / %d)\n", a2, a3);
  }
  return v6 * (unsigned __int64)(unsigned int)(a3 * a2) / 0xA0EEBB;
}
