__int64 __fastcall soc_to_dri_pack_parse(__int64 a1, int a2, unsigned __int8 a3, unsigned __int8 a4)
{
  unsigned __int64 v7; // x23
  unsigned __int16 *v8; // x20
  __int64 v9; // x1
  unsigned int v10; // w5
  unsigned int v11; // w8
  unsigned int v12; // w6
  unsigned int v13; // w8
  unsigned int v14; // w7
  unsigned int v15; // w8
  int v16; // w23
  __int64 result; // x0
  __int16 v18; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v19; // [xsp+38h] [xbp-8h]

  v7 = (unsigned int)(a2 + 12);
  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = 24;
  v8 = (unsigned __int16 *)_kmalloc_noprof(v7, 3520);
  v9 = *(_QWORD *)(a1 + 48);
  if ( !v8 )
  {
    dev_printk(&unk_134C0, v9, "[%s:%d] kzalloc_ err!\n", "soc_to_dri_pack_parse", 1754);
LABEL_16:
    result = 0xFFFFFFFFLL;
    goto LABEL_17;
  }
  dev_printk(&unk_142BB, v9, "[%s:%d] enter\n", "soc_to_dri_pack_parse", 1758);
  if ( (unsigned int)soc_to_dri_pack_recv(a1, (__int64)v8, v7, (__int64)&v18) )
  {
    dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] pack parse err\n", "soc_to_dri_pack_parse", 1767);
    kfree(v8);
    goto LABEL_16;
  }
  if ( v7 < 2 )
    goto LABEL_18;
  v10 = bswap32(*v8) >> 16;
  *v8 = v10;
  if ( (v7 & 0xFFFFFFFE) == 2 )
    goto LABEL_18;
  v11 = bswap32(v8[1]);
  v12 = HIWORD(v11);
  v8[1] = HIWORD(v11);
  if ( v7 < 0xA
    || (v7 & 0xFFFFFFFE) == 0xA
    || (v13 = bswap32(v8[5]), v14 = HIWORD(v13), v8[5] = HIWORD(v13), (v7 & 0xFFFFFFFC) == 4)
    || (v15 = bswap32(*((_DWORD *)v8 + 1)), *((_DWORD *)v8 + 1) = v15, v7 < 0x10) )
  {
LABEL_18:
    __break(1u);
  }
  v16 = *((_DWORD *)v8 + 3);
  dev_printk(
    &unk_13D4F,
    *(_QWORD *)(a1 + 48),
    "[%s:%d] header= 0x%x, size= 0x%x, length= 0x%x, checksum= 0x%x,module= 0x%x, command= 0x%x, length=0x%x, cmd_status = %d\n",
    "soc_to_dri_pack_parse",
    1784,
    v10,
    v12,
    v14,
    v15,
    *((unsigned __int8 *)v8 + 8),
    *((unsigned __int8 *)v8 + 9),
    v14,
    v16);
  if ( *((unsigned __int8 *)v8 + 8) != a3 || v16 || *((unsigned __int8 *)v8 + 9) != a4 )
  {
    dev_printk(
      &unk_134C0,
      *(_QWORD *)(a1 + 48),
      "[%s:%d] soc_to_dri_pack_parse err!!!\n",
      "soc_to_dri_pack_parse",
      1789);
    goto LABEL_16;
  }
  dev_printk(&unk_13D4F, *(_QWORD *)(a1 + 48), "[%s:%d] soc_to_dri_pack_parse ok\n", "soc_to_dri_pack_parse", 1787);
  kfree(v8);
  result = 0;
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
