__int64 __fastcall ipa3_ap_iommu_unmap(__int64 result, __int64 a2, unsigned int a3)
{
  unsigned __int64 v3; // x26
  __int64 v5; // x20
  unsigned __int64 v6; // x25
  _DWORD *v7; // x8
  unsigned int v8; // w9
  __int64 v9; // x24
  unsigned int v10; // w10
  __int64 v11; // x23
  __int64 v12; // x0
  __int64 v13; // x1
  __int64 v14; // x1
  __int64 v15; // x0
  _QWORD v16[2]; // [xsp+0h] [xbp-10h] BYREF

  v16[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 < 4 )
  {
LABEL_8:
    _ReadStatusReg(SP_EL0);
  }
  else
  {
    v3 = a3 >> 2;
    v5 = result;
    v6 = 0;
    while ( 1 )
    {
      v7 = (_DWORD *)(a2 + 4 * v6);
      v8 = bswap32(v7[1]);
      v9 = bswap32(*v7 & 0xF0FFFF);
      v10 = (v8 & 0xFFF) + bswap32(v7[2]);
      v16[0] = v8 & 0xFFFFF000;
      v11 = (v10 + 4095) & 0xFFFFF000;
      if ( ipa3_ctx )
      {
        v12 = *(_QWORD *)(ipa3_ctx + 34160);
        if ( v12 )
          ipc_log_string(
            v12,
            "ipa %s:%d unmapping 0x%lx to 0x%pa size %d\n",
            "ipa3_ap_iommu_unmap",
            11282,
            v9,
            v16,
            v11);
      }
      result = iommu_unmap(*(_QWORD *)(v5 + 16), v9, v11);
      if ( (_DWORD)v11 != (_DWORD)result )
        break;
      v6 += 3LL;
      if ( v6 >= v3 )
        goto LABEL_8;
    }
    printk(&unk_3FD680, v13);
    v15 = printk(&unk_3AED39, v14);
    __break(0x800u);
    return ipa3_alloc_pkt_init(v15);
  }
  return result;
}
