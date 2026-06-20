__int64 __fastcall tsv_qtimer_write(__int64 a1)
{
  unsigned __int64 StatusReg; // x9
  __int64 v2; // x8
  int v3; // w8
  unsigned int v4; // w11
  unsigned int v5; // w8
  __int64 v6; // x11
  unsigned int v7; // w8
  void *v9; // x0

  __isb(0xFu);
  StatusReg = _ReadStatusReg(CNTVCT_EL0);
  if ( !a1 )
  {
    v9 = &unk_823C;
    goto LABEL_11;
  }
  v2 = *(unsigned int *)(a1 + 260);
  if ( (unsigned int)(v2 - 254) <= 0xFFFFFEFF )
    goto LABEL_9;
  if ( (unsigned int)v2 >= 0x100 )
    goto LABEL_12;
  *(_WORD *)(a1 + 2 + v2) = 2053;
  v3 = *(_DWORD *)(a1 + 260);
  v4 = v3 - 246;
  v5 = v3 + 2;
  *(_DWORD *)(a1 + 260) = v5;
  if ( v4 <= 0xFFFFFEFF )
  {
LABEL_9:
    v9 = &unk_82CF;
LABEL_11:
    printk(v9, "tsv_write_data");
    return (unsigned int)-22;
  }
  if ( v5 < 0x100 )
  {
    v6 = *(unsigned int *)(a1 + 260);
    if ( (unsigned int)v6 <= 0xFF )
    {
      *(_QWORD *)(a1 + 2 + v6) = StatusReg;
      v7 = 0;
      *(_DWORD *)(a1 + 260) += 8;
      return v7;
    }
  }
LABEL_12:
  __break(0x5512u);
  return tsv_pointer_write();
}
