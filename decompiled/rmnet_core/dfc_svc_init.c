__int64 __fastcall dfc_svc_init(__int64 result)
{
  unsigned int *v1; // x19
  __int64 v2; // x20
  _WORD *v3; // x22
  int v4; // w0
  unsigned int v5; // w9
  unsigned int v6; // w10
  int v7; // w0
  int v8; // w21
  _WORD *v9; // x22
  int v10; // w0
  int v11; // w9
  int v12; // w21
  __int64 *v13; // x20
  __int64 qmi_pt; // x0
  void *v15; // x0
  void *v16; // x0
  __int64 v17; // x8
  __int64 v18; // x8
  __int64 v19; // x0
  __int64 v20; // x1
  unsigned __int64 StatusReg; // x21
  __int64 v22; // x22
  __int64 (__fastcall *v23)(_QWORD, _QWORD); // x0
  __int64 v24; // [xsp+0h] [xbp-50h] BYREF
  __int64 v25; // [xsp+8h] [xbp-48h]
  __int64 v26; // [xsp+10h] [xbp-40h]
  __int64 v27; // [xsp+18h] [xbp-38h]
  __int64 v28; // [xsp+20h] [xbp-30h]
  __int64 v29; // [xsp+28h] [xbp-28h]
  __int64 v30; // [xsp+30h] [xbp-20h]
  __int64 v31; // [xsp+38h] [xbp-18h]
  __int64 v32; // [xsp+40h] [xbp-10h]
  __int64 v33; // [xsp+48h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(result + 416) == 1 )
    goto LABEL_42;
  v1 = (unsigned int *)result;
  v31 = 0;
  v32 = 0;
  v29 = 0;
  v30 = 0;
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  v24 = 0;
  v2 = _kmalloc_cache_noprof(unregister_netdevice_queue, 2336, 12);
  if ( !v2 )
    goto LABEL_41;
  while ( 1 )
  {
    v3 = (_WORD *)_kmalloc_cache_noprof(synchronize_rcu, 2336, 4);
    if ( !v3 )
      break;
    v4 = qmi_txn_init(v1 + 8, &v24, &dfc_bind_client_resp_msg_v01_ei, v3);
    if ( v4 < 0 )
    {
      v8 = v4;
      v15 = &unk_2D786;
LABEL_30:
      printk(v15, "dfc_bind_client_req");
      goto LABEL_9;
    }
    v5 = v1[88];
    v6 = v1[89];
    *(_BYTE *)v2 = 1;
    *(_DWORD *)(v2 + 4) = v5;
    *(_DWORD *)(v2 + 8) = v6;
    v7 = qmi_send_request(v1 + 8, v1 + 84, &v24, 32, 11, &dfc_bind_client_req_msg_v01_ei, v2);
    if ( v7 < 0 )
    {
      v8 = v7;
      qmi_txn_cancel(&v24);
      v15 = &unk_2CDDC;
      goto LABEL_30;
    }
    v8 = qmi_txn_wait(&v24, 250);
    if ( v8 < 0 )
    {
      v15 = &unk_2D7B0;
      goto LABEL_30;
    }
    if ( *v3 )
    {
      printk(&unk_2D31A, "dfc_bind_client_req");
      v8 = -(unsigned __int16)*v3;
    }
LABEL_9:
    kfree(v3);
    kfree(v2);
    if ( v8 < 0 )
      goto LABEL_41;
    v31 = 0;
    v32 = 0;
    v29 = 0;
    v30 = 0;
    v27 = 0;
    v28 = 0;
    v25 = 0;
    v26 = 0;
    v24 = 0;
    v2 = _kmalloc_cache_noprof(synchronize_rcu, 2336, 4);
    if ( !v2 )
      goto LABEL_41;
    v9 = (_WORD *)_kmalloc_cache_noprof(synchronize_rcu, 2336, 4);
    if ( !v9 )
      break;
    v10 = qmi_txn_init(v1 + 8, &v24, &dfc_indication_register_resp_msg_v01_ei, v9);
    if ( v10 < 0 )
    {
      v12 = v10;
      v16 = &unk_2D786;
LABEL_34:
      printk(v16, "dfc_indication_register_req");
      goto LABEL_19;
    }
    v11 = dfc_ps_ext;
    *(_WORD *)v2 = 257;
    if ( !v11 )
      *(_WORD *)(v2 + 2) = 257;
    v12 = qmi_send_request(v1 + 8, v1 + 84, &v24, 1, 8, &dfc_indication_register_req_msg_v01_ei, v2);
    if ( v12 < 0 )
    {
      qmi_txn_cancel(&v24);
      v16 = &unk_2CDDC;
      goto LABEL_34;
    }
    v12 = qmi_txn_wait(&v24, 250);
    if ( v12 < 0 )
    {
      v16 = &unk_2D7B0;
      goto LABEL_34;
    }
    if ( *v9 )
    {
      printk(&unk_2D31A, "dfc_indication_register_req");
      v12 = -(unsigned __int16)*v9;
    }
LABEL_19:
    kfree(v9);
    result = kfree(v2);
    if ( v12 < 0 )
      goto LABEL_41;
    if ( v1[104] == 1 )
      goto LABEL_42;
    v13 = (__int64 *)(v1 - 4);
    while ( 1 )
    {
      result = rtnl_trylock(result);
      if ( (_DWORD)result )
        break;
      if ( v1[104] )
        goto LABEL_42;
    }
    qmi_pt = rmnet_get_qmi_pt(*v13);
    if ( !qmi_pt )
    {
      result = rtnl_unlock(0);
      goto LABEL_42;
    }
    v17 = v1[103];
    if ( (unsigned int)v17 < 2 )
    {
      *(_QWORD *)(qmi_pt + 8 * v17 + 40) = 0;
      v18 = v1[103];
      if ( (unsigned int)v18 <= 1 )
      {
        *(_QWORD *)(qmi_pt + 8 * v18 + 24) = v13;
        v19 = trace_dfc_client_state_up_0(v1[103], v1[87], v1[88], v1[89]);
        rtnl_unlock(v19);
        result = printk(&unk_2D0F6, v20);
        goto LABEL_42;
      }
    }
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v22 = *(_QWORD *)(StatusReg + 80);
    v23 = unregister_netdevice_queue;
    *(_QWORD *)(StatusReg + 80) = &dfc_bind_client_req__alloc_tag;
    v2 = _kmalloc_cache_noprof(v23, 2336, 12);
    *(_QWORD *)(StatusReg + 80) = v22;
    if ( !v2 )
      goto LABEL_41;
  }
  kfree(v2);
LABEL_41:
  result = printk(&unk_2CD12, "dfc_svc_init");
LABEL_42:
  _ReadStatusReg(SP_EL0);
  return result;
}
