_QWORD *__fastcall cm_update_phymode_on_roam(
        int a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *result; // x0
  _QWORD *v13; // x19
  __int64 v14; // x3
  int *v15; // x1
  _QWORD *v16; // x2
  _QWORD v17[3]; // [xsp+0h] [xbp-30h] BYREF
  int v18; // [xsp+18h] [xbp-18h]
  int v19; // [xsp+20h] [xbp-10h] BYREF
  __int16 v20; // [xsp+24h] [xbp-Ch]
  __int64 v21; // [xsp+28h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = _cds_get_context(54, (__int64)"cm_update_phymode_on_roam", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( result )
  {
    v13 = result;
    v20 = 0;
    v19 = 0;
    memset(v17, 0, sizeof(v17));
    v18 = 0;
    if ( (is_multi_link_roam(a2) & 1) != 0 )
    {
      mlo_roam_get_bssid_chan_for_link(a1, a2, (int)&v19, (int)v17);
      v14 = v13[65] + 488LL * (unsigned __int8)a1;
      v15 = &v19;
      v16 = v17;
    }
    else
    {
      v14 = v13[65] + 488LL * (unsigned __int8)a1;
      v15 = (int *)(a2 + 14);
      v16 = (_QWORD *)(a2 + 2464);
    }
    result = (_QWORD *)wma_update_phymode_on_roam(v13, v15, v16, v14);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
