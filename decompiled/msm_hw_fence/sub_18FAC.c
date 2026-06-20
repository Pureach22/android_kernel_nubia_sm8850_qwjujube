void __fastcall sub_18FAC(__int64 a1)
{
  unsigned __int64 StatusReg; // x20
  __int64 v2; // x21

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &parse_client_queue_dt_props__alloc_tag;
  _kmalloc_noprof(a1, 3520);
  *(_QWORD *)(StatusReg + 80) = v2;
  JUMPOUT(0x1895C);
}
