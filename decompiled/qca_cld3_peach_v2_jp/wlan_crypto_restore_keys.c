__int64 __fastcall wlan_crypto_restore_keys(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x8
  __int64 v10; // x19
  __int64 v11; // x20
  __int64 comp_private_obj; // x0
  __int64 v13; // x1
  __int64 v14; // x0
  __int64 v15; // x8
  void (__fastcall *v16)(__int64, __int64, __int64 *, __int64); // x8
  __int64 v17; // x9
  __int64 v18; // x3
  const char *v19; // x2
  __int64 v20; // x0
  __int64 v21; // x1
  __int64 v22; // x0
  __int64 v23; // x8
  void (__fastcall *v24)(__int64, __int64, __int64 *, __int64); // x8
  __int64 v25; // x9
  __int64 v26; // x3
  __int64 v27; // x0
  __int64 v28; // x1
  __int64 v29; // x0
  __int64 v30; // x8
  void (__fastcall *v31)(__int64, __int64, __int64 *, __int64); // x8
  __int64 v32; // x9
  __int64 v33; // x3
  __int64 v34; // x0
  __int64 v35; // x1
  __int64 v36; // x0
  __int64 v37; // x8
  void (__fastcall *v38)(__int64, __int64, __int64 *, __int64); // x8
  __int64 v39; // x9
  __int64 v40; // x3
  __int64 v41; // [xsp+0h] [xbp-10h] BYREF
  __int64 v42; // [xsp+8h] [xbp-8h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(result + 152);
  WORD2(v41) = -1;
  LODWORD(v41) = -1;
  if ( !v9 )
  {
    v19 = "%s: pdev is NULL";
LABEL_47:
    result = qdf_trace_msg(0x1Cu, 2u, v19, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_crypto_restore_keys", v41);
    goto LABEL_48;
  }
  v10 = *(_QWORD *)(v9 + 80);
  if ( !v10 )
  {
    v19 = "%s: psoc is NULL";
    goto LABEL_47;
  }
  if ( (*(_BYTE *)(result + 52) & 1) != 0 )
  {
    v11 = result;
    comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(result, 14);
    if ( comp_private_obj )
    {
      v13 = *(_QWORD *)(comp_private_obj + 288);
      v14 = v11;
      if ( v13 && *(_BYTE *)(v13 + 1) == 1 )
      {
        v15 = *(_QWORD *)(v10 + 2128);
        if ( !v15 )
          goto LABEL_49;
        v16 = *(void (__fastcall **)(__int64, __int64, __int64 *, __int64))(v15 + 712);
        if ( v16 )
        {
          v17 = *(_QWORD *)(v13 + 32);
          if ( v17 )
            v18 = *(unsigned int *)(v17 + 8);
          else
            v18 = 17;
          if ( *((_DWORD *)v16 - 1) != -871156935 )
            __break(0x8228u);
          v16(v11, v13, &v41, v18);
          v14 = v11;
        }
      }
      v20 = wlan_objmgr_vdev_get_comp_private_obj(v14, 14);
      if ( v20 )
      {
        v21 = *(_QWORD *)(v20 + 296);
        v22 = v11;
        if ( v21 && *(_BYTE *)(v21 + 1) == 1 )
        {
          v23 = *(_QWORD *)(v10 + 2128);
          if ( !v23 )
            goto LABEL_49;
          v24 = *(void (__fastcall **)(__int64, __int64, __int64 *, __int64))(v23 + 712);
          if ( v24 )
          {
            v25 = *(_QWORD *)(v21 + 32);
            if ( v25 )
              v26 = *(unsigned int *)(v25 + 8);
            else
              v26 = 17;
            if ( *((_DWORD *)v24 - 1) != -871156935 )
              __break(0x8228u);
            v24(v11, v21, &v41, v26);
            v22 = v11;
          }
        }
        v27 = wlan_objmgr_vdev_get_comp_private_obj(v22, 14);
        if ( v27 )
        {
          v28 = *(_QWORD *)(v27 + 304);
          v29 = v11;
          if ( !v28 || *(_BYTE *)(v28 + 1) != 1 )
            goto LABEL_39;
          v30 = *(_QWORD *)(v10 + 2128);
          if ( v30 )
          {
            v31 = *(void (__fastcall **)(__int64, __int64, __int64 *, __int64))(v30 + 712);
            if ( v31 )
            {
              v32 = *(_QWORD *)(v28 + 32);
              if ( v32 )
                v33 = *(unsigned int *)(v32 + 8);
              else
                v33 = 17;
              if ( *((_DWORD *)v31 - 1) != -871156935 )
                __break(0x8228u);
              v31(v11, v28, &v41, v33);
              v29 = v11;
            }
LABEL_39:
            v34 = wlan_objmgr_vdev_get_comp_private_obj(v29, 14);
            if ( v34 )
            {
              v35 = *(_QWORD *)(v34 + 312);
              v36 = v11;
              if ( !v35 || *(_BYTE *)(v35 + 1) != 1 )
              {
LABEL_54:
                result = wlan_objmgr_iterate_peerobj_list(v36, crypto_plumb_peer_keys, v10, 19);
                goto LABEL_48;
              }
              v37 = *(_QWORD *)(v10 + 2128);
              if ( v37 )
              {
                v38 = *(void (__fastcall **)(__int64, __int64, __int64 *, __int64))(v37 + 712);
                if ( v38 )
                {
                  v39 = *(_QWORD *)(v35 + 32);
                  if ( v39 )
                    v40 = *(unsigned int *)(v39 + 8);
                  else
                    v40 = 17;
                  if ( *((_DWORD *)v38 - 1) != -871156935 )
                    __break(0x8228u);
                  v38(v11, v35, &v41, v40);
                  v36 = v11;
                }
                goto LABEL_54;
              }
              goto LABEL_49;
            }
            goto LABEL_46;
          }
LABEL_49:
          v19 = "%s: tx_ops is NULL";
          goto LABEL_47;
        }
      }
    }
LABEL_46:
    qdf_trace_msg(
      0x1Cu,
      2u,
      "%s: crypto_priv NULL",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_crypto_vdev_get_comp_params",
      v41,
      v42);
    v19 = "%s: crypto_priv is NULL";
    goto LABEL_47;
  }
LABEL_48:
  _ReadStatusReg(SP_EL0);
  return result;
}
