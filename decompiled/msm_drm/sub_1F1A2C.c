void __fastcall sub_1F1A2C(
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
  unsigned __int64 StatusReg; // x22
  __int64 v10; // x23

  StatusReg = _ReadStatusReg(SP_EL0);
  v10 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &dsi_panel_parse_esd_status_len__alloc_tag;
  if ( (a9 & 0x8000000000000000LL) == 0 )
    _kmalloc_noprof(4LL * HIDWORD(a9), 3520);
  *(_QWORD *)(StatusReg + 80) = v10;
  JUMPOUT(0x1F1944);
}
