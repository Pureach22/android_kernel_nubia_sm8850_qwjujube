__int64 __fastcall tsv_pointer_write(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  int v3; // w8
  unsigned int v4; // w10
  unsigned int v5; // w8
  __int64 v6; // x10
  unsigned int v7; // w8
  void *v9; // x0

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
  *(_WORD *)(a1 + 2 + v2) = 2050;
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
  if ( v5 >= 0x100 || (v6 = *(unsigned int *)(a1 + 260), (unsigned int)v6 > 0xFF) )
  {
LABEL_12:
    __break(0x5512u);
    JUMPOUT(0x651C);
  }
  *(_QWORD *)(a1 + 2 + v6) = a2;
  v7 = 0;
  *(_DWORD *)(a1 + 260) += 8;
  return v7;
}
