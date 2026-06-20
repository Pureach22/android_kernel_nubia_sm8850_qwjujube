__int64 __fastcall rmnet_mem_nl_cmd_update_pool_size(__int64 a1, __int64 a2)
{
  __int64 v3; // x10
  __int64 v4; // x1
  int v5; // w9
  _BOOL4 v6; // w21
  int v7; // w0
  __int64 v8; // x3
  __int64 v10; // [xsp+0h] [xbp-20h] BYREF
  __int64 v11; // [xsp+8h] [xbp-18h]
  int v12; // [xsp+10h] [xbp-10h]
  __int64 v13; // [xsp+18h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a2 + 32);
  v12 = 0;
  v10 = 0;
  v11 = 0;
  ++qword_8E08;
  v4 = *(_QWORD *)(v3 + 16);
  if ( !v4 )
  {
    v7 = 401;
    goto LABEL_28;
  }
  nla_memcpy(&v10, v4, 20);
  if ( (v12 & 1) != 0 && (unsigned int)(v10 - 1) <= 0x3E7 )
  {
    LODWORD(target_pool_size) = v10;
    LODWORD(max_pool_size) = v10;
    v5 = 1;
    v6 = (unsigned int)v10 > (unsigned int)static_pool_size;
    if ( (v12 & 2) == 0 )
    {
LABEL_10:
      if ( (v12 & 4) == 0 )
        goto LABEL_18;
      goto LABEL_11;
    }
  }
  else
  {
    v5 = 0;
    v6 = 0;
    if ( (v12 & 2) == 0 )
      goto LABEL_10;
  }
  if ( (unsigned int)(HIDWORD(v10) - 1) > 0x3E7 )
    goto LABEL_10;
  HIDWORD(target_pool_size) = HIDWORD(v10);
  HIDWORD(max_pool_size) = HIDWORD(v10);
  if ( v6 )
  {
    v5 = 1;
    v6 = 1;
    goto LABEL_10;
  }
  v5 = 1;
  v6 = HIDWORD(v10) > HIDWORD(static_pool_size);
  if ( (v12 & 4) == 0 )
    goto LABEL_18;
LABEL_11:
  if ( (unsigned int)(v11 - 1) <= 0x3E7 )
  {
    LODWORD(qword_1C0) = v11;
    LODWORD(qword_1B0) = v11;
    v5 = 1;
    v6 = v6 || (unsigned int)v11 > (unsigned int)qword_8C60;
  }
LABEL_18:
  if ( (v12 & 8) == 0 || (unsigned int)(HIDWORD(v11) - 1) > 0x3E7 )
  {
LABEL_22:
    v7 = 400;
    if ( !v5 )
      goto LABEL_28;
    goto LABEL_23;
  }
  HIDWORD(qword_1C0) = HIDWORD(v11);
  HIDWORD(qword_1B0) = HIDWORD(v11);
  if ( v6 )
  {
    v5 = 1;
    v6 = 1;
    goto LABEL_22;
  }
  v6 = HIDWORD(v11) > HIDWORD(qword_8C60);
  v7 = 400;
LABEL_23:
  if ( mem_wq )
  {
    cancel_delayed_work_sync(&pool_adjust_work);
    if ( v6 )
      v8 = 0;
    else
      v8 = 750;
    queue_delayed_work_on(32, mem_wq, &pool_adjust_work, v8);
    v7 = 400;
  }
LABEL_28:
  rmnet_mem_genl_send_int_to_userspace_no_info(v7, a2);
  _ReadStatusReg(SP_EL0);
  return 0;
}
