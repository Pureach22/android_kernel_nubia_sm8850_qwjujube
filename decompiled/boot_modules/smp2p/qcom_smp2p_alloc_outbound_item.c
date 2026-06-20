__int64 __fastcall qcom_smp2p_alloc_outbound_item(_QWORD *a1)
{
  unsigned int v2; // w21
  unsigned int v3; // w22
  int v4; // w0
  unsigned __int64 v5; // x19
  unsigned __int64 v6; // x0
  int v7; // w8
  __int64 v8; // x1
  __int64 v9; // x0
  unsigned __int64 v10; // x0
  unsigned int v11; // w8
  __int64 v12; // x0
  _QWORD v14[2]; // [xsp+0h] [xbp-10h] BYREF

  v14[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *((_DWORD *)a1 + 7);
  v3 = *((_DWORD *)a1 + 13);
  v4 = qcom_smem_alloc(v3, v2, 340);
  if ( (v4 & 0x80000000) == 0 || (LODWORD(v5) = v4, v4 == -17) )
  {
    v6 = qcom_smem_get(v3, v2, 0);
    v5 = v6;
    if ( v6 >= 0xFFFFFFFFFFFFF001LL )
    {
      dev_err(*a1, "Unable to acquire local smp2p item\n");
    }
    else
    {
      memset((void *)(v6 + 4), 0, 0x150u);
      *(_DWORD *)v5 = 1347244836;
      *(_WORD *)(v5 + 8) = *((_DWORD *)a1 + 12);
      v7 = *((_DWORD *)a1 + 13);
      *(_DWORD *)(v5 + 12) = 16;
      *(_BYTE *)(v5 + 7) = 0;
      *(_WORD *)(v5 + 10) = v7;
      *(_WORD *)(v5 + 5) = 1;
      v8 = *((unsigned int *)a1 + 6);
      v9 = *((unsigned int *)a1 + 13);
      v14[0] = 0;
      v10 = qcom_smem_get(v9, v8, v14);
      v11 = 0;
      if ( v10 <= 0xFFFFFFFFFFFFF000LL )
        v11 = *(unsigned __int8 *)(v10 + 4);
      __dsb(0xEu);
      if ( v11 <= 1 )
        LOBYTE(v11) = 1;
      *(_BYTE *)(v5 + 4) = v11;
      __dsb(0xEu);
      v12 = a1[17];
      if ( v12 )
      {
        mbox_send_message(v12, 0);
        mbox_client_txdone(a1[17], 0);
      }
      else
      {
        regmap_write(a1[8], *((unsigned int *)a1 + 18), 1LL << *((_DWORD *)a1 + 19));
      }
      a1[2] = v5;
      LODWORD(v5) = 0;
    }
  }
  else if ( v4 == -517 )
  {
    LODWORD(v5) = -517;
  }
  else
  {
    dev_err(*a1, "unable to allocate local smp2p item\n");
  }
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v5;
}
