__int64 __fastcall ml_get_link_state_req_cb(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x20
  __int64 v10; // x8
  __int64 v11; // x19
  __int64 v12; // x21
  __int64 v13; // x9
  unsigned int (__fastcall *v14)(__int64, __int64 *); // x8
  __int64 v15; // x0
  unsigned int v16; // w19
  const char *v17; // x2
  __int64 v19; // [xsp+0h] [xbp-10h] BYREF
  __int64 v20; // [xsp+8h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 8);
  *(_WORD *)((char *)&v19 + 5) = 0;
  *(_DWORD *)((char *)&v19 + 1) = 0;
  if ( !v9 )
  {
    v16 = 4;
    v17 = "%s: null input vdev";
    goto LABEL_13;
  }
  v10 = *(_QWORD *)(v9 + 216);
  if ( !v10 || (v11 = *(_QWORD *)(v10 + 80)) == 0 )
  {
    v16 = 29;
    v17 = "%s: null psoc";
    goto LABEL_13;
  }
  v12 = *(_QWORD *)(v11 + 2128);
  if ( v12 == -1984 )
  {
    v16 = 29;
    v17 = "%s: tx_ops is null!";
    goto LABEL_13;
  }
  if ( (wlan_vdev_mlme_is_mlo_vdev(v9, a2, a3, a4, a5, a6, a7, a8, a9) & 1) == 0 )
  {
    v16 = 0;
    v17 = "%s: vdev is not MLO vdev";
    goto LABEL_13;
  }
  v13 = *(_QWORD *)(v9 + 1360);
  LOBYTE(v19) = *(_BYTE *)(v9 + 168);
  qdf_mem_copy((char *)&v19 + 1, (const void *)(v13 + 17), 6u);
  v14 = *(unsigned int (__fastcall **)(__int64, __int64 *))(v12 + 2008);
  if ( !v14 )
  {
    v16 = 29;
    v17 = "%s: handler is not registered";
    goto LABEL_13;
  }
  v15 = v11;
  if ( *((_DWORD *)v14 - 1) != -962729502 )
    __break(0x8228u);
  v16 = 0;
  if ( v14(v15, &v19) )
  {
    v17 = "%s: failed to send ml link info command to FW";
LABEL_13:
    qdf_trace_msg(0x8Fu, 2u, v17, a2, a3, a4, a5, a6, a7, a8, a9, "ml_get_link_state_req_cb", v19, v20);
  }
  _ReadStatusReg(SP_EL0);
  return v16;
}
