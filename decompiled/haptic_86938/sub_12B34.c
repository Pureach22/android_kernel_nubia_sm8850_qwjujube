void __fastcall sub_12B34(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        unsigned int a11)
{
  unsigned __int64 StatusReg; // x23
  __int64 v12; // x24

  StatusReg = _ReadStatusReg(SP_EL0);
  v12 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &awrw_store__alloc_tag;
  _kmalloc_noprof(a11, 3264);
  *(_QWORD *)(StatusReg + 80) = v12;
  JUMPOUT(0x128A4);
}
