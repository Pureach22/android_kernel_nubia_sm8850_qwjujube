void __fastcall sub_114C74(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9)
{
  __int64 v9; // x23
  unsigned __int64 StatusReg; // x27
  __int64 v11; // x28
  __int64 v12; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v11 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_soc_util_get_dt_gpio_req_tbl__alloc_tag_396;
  v12 = _kvmalloc_node_noprof(24LL * HIDWORD(a9), 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v11;
  *(_QWORD *)(v9 + 16) = v12;
  if ( !v12 )
    JUMPOUT(0x114818);
  JUMPOUT(0x114734);
}
