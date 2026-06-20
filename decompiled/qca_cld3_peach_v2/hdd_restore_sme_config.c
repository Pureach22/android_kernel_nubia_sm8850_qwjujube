__int64 __fastcall hdd_restore_sme_config(__int64 a1, int a2, char a3, int a4)
{
  __int64 result; // x0
  __int64 v9; // x19
  __int64 vdev_by_user; // x0
  __int64 v11; // x21
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // [xsp+8h] [xbp-38h] BYREF
  __int64 v29; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v30)(); // [xsp+18h] [xbp-28h]
  __int64 (__fastcall *v31)(); // [xsp+20h] [xbp-20h]
  __int64 v32; // [xsp+28h] [xbp-18h]
  __int64 v33; // [xsp+30h] [xbp-10h]
  __int64 v34; // [xsp+38h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v32 = 0;
  v33 = 0;
  v30 = nullptr;
  v31 = nullptr;
  v28 = 0;
  v29 = 0;
  result = _qdf_mem_malloc(0x18u, "hdd_restore_sme_config", 2663);
  if ( result )
  {
    v9 = result;
    vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 5, "hdd_restore_sme_config");
    if ( vdev_by_user )
    {
      v11 = vdev_by_user;
      *(_QWORD *)v9 = vdev_by_user;
      *(_BYTE *)(v9 + 12) = a3 & 1;
      *(_DWORD *)(v9 + 8) = a2;
      *(_DWORD *)(v9 + 16) = a4;
      v29 = v9;
      v30 = hdd_restore_sme_config_cb;
      v31 = hdd_restore_sme_config_flush_cb;
      result = scheduler_post_message_debug(
                 0x33u,
                 0x48u,
                 72,
                 (unsigned __int16 *)&v28,
                 0xA7Cu,
                 (__int64)"hdd_restore_sme_config");
      if ( (_DWORD)result )
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: status %d",
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          "hdd_restore_sme_config",
          (unsigned int)result);
        _hdd_objmgr_put_vdev_by_user(v11, 5, "hdd_restore_sme_config");
        result = _qdf_mem_free(v9);
      }
    }
    else
    {
      _qdf_mem_free(v9);
      result = qdf_trace_msg(
                 0x33u,
                 8u,
                 "%s: no vdev from link info",
                 v20,
                 v21,
                 v22,
                 v23,
                 v24,
                 v25,
                 v26,
                 v27,
                 "hdd_restore_sme_config");
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
