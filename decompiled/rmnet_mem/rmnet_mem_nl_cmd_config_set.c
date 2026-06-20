__int64 __fastcall rmnet_mem_nl_cmd_config_set(__int64 a1, __int64 a2)
{
  __int64 v2; // x20
  int v3; // w0
  int v5; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = 0;
  ++qword_8E40;
  if ( *(_QWORD *)(*(_QWORD *)(a2 + 32) + 40LL) )
  {
    v2 = a2;
    nla_memcpy(&v5, *(_QWORD *)(*(_QWORD *)(a2 + 32) + 40LL), 4);
    if ( (v5 & 1) != 0 && (ipa_config & 1) == 0 )
    {
      ipa_config = v5;
      if ( HIDWORD(qword_8C60) != 603 && HIDWORD(qword_8C60) )
      {
        if ( HIDWORD(qword_1C0) == 603 )
        {
          HIDWORD(qword_1C0) = 600;
          HIDWORD(qword_1B0) = 600;
        }
      }
      else
      {
        HIDWORD(qword_1C0) = 600;
        HIDWORD(qword_1B0) = 600;
        cancel_delayed_work_sync(&pool_adjust_work);
        queue_delayed_work_on(32, mem_wq, &pool_adjust_work, 0);
      }
    }
    v3 = 400;
    a2 = v2;
  }
  else
  {
    v3 = 401;
  }
  rmnet_mem_genl_send_int_to_userspace_no_info(v3, a2);
  _ReadStatusReg(SP_EL0);
  return 0;
}
