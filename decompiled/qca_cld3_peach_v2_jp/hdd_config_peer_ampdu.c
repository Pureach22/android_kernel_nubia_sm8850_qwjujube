__int64 __fastcall hdd_config_peer_ampdu(
        _QWORD *a1,
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
  __int64 v10; // x21
  __int64 v11; // x9
  __int64 v12; // x1
  int v13; // w8
  __int64 v14; // x22
  __int64 result; // x0
  _QWORD *v16; // x23
  __int64 vdev_by_user; // x0
  __int64 v18; // x19
  int bss_peer_mac; // w20
  const char *v20; // x2
  __int64 v21; // [xsp+0h] [xbp-10h] BYREF
  __int64 v22; // [xsp+8h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a2 + 824);
  if ( v10 )
  {
    v11 = *a1;
    v12 = *(_QWORD *)(a2 + 280);
    WORD2(v21) = 0;
    LODWORD(v21) = 0;
    v13 = *(_DWORD *)(v11 + 40);
    v14 = *(_QWORD *)(v11 + 24);
    if ( v13 > 1 )
    {
      if ( v13 == 3 )
      {
LABEL_12:
        if ( !v12 )
        {
          v20 = "%s: sap must provide peer mac attr";
          goto LABEL_18;
        }
        v16 = a1;
        nla_memcpy(&v21, v12, 6);
LABEL_14:
        result = sme_set_peer_ampdu(
                   *(_QWORD *)(v14 + 16),
                   *((unsigned __int8 *)v16 + 8),
                   &v21,
                   *(unsigned __int16 *)(v10 + 4));
        goto LABEL_19;
      }
      if ( v13 != 2 )
      {
LABEL_15:
        v20 = "%s: mode not support";
        goto LABEL_18;
      }
    }
    else if ( v13 )
    {
      if ( v13 != 1 )
        goto LABEL_15;
      goto LABEL_12;
    }
    v16 = a1;
    vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 6, "hdd_config_peer_ampdu");
    if ( !vdev_by_user )
    {
      v20 = "%s: vdev is null";
      goto LABEL_18;
    }
    v18 = vdev_by_user;
    bss_peer_mac = wlan_vdev_get_bss_peer_mac(vdev_by_user, &v21, a3, a4, a5, a6, a7, a8, a9, a10);
    _hdd_objmgr_put_vdev_by_user(v18, 6, "hdd_config_peer_ampdu");
    if ( bss_peer_mac )
    {
      v20 = "%s: fail to get bss peer mac";
LABEL_18:
      qdf_trace_msg(0x33u, 8u, v20, a3, a4, a5, a6, a7, a8, a9, a10, "hdd_config_peer_ampdu", v21, v22);
      result = 4294967274LL;
      goto LABEL_19;
    }
    goto LABEL_14;
  }
  result = 0;
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
