void sub_CB28()
{
  __int64 v0; // x20
  int v1; // w28
  __int64 v2; // x29
  unsigned __int64 v3; // x9
  bool v4; // zf
  unsigned __int64 StatusReg; // x20
  __int64 v6; // x21
  unsigned int v7; // w9
  __int64 v8; // x1
  __int64 v9; // x0

  v3 = (unsigned __int64)(v0 - 1) >> 12;
  v4 = v0 == 4096;
  StatusReg = _ReadStatusReg(SP_EL0);
  v6 = *(_QWORD *)(StatusReg + 80);
  v7 = 64 - __clz(v3);
  *(_QWORD *)(StatusReg + 80) = &fast_smmu_alloc_atomic__alloc_tag;
  if ( v4 )
    v8 = 0;
  else
    v8 = v7;
  v9 = _alloc_pages_noprof(v1 | 0x100u, v8, 0, 0);
  *(_QWORD *)(StatusReg + 80) = v6;
  *(_QWORD *)(v2 - 16) = v9;
  if ( !v9 )
    JUMPOUT(0xCA98);
  JUMPOUT(0xC620);
}
