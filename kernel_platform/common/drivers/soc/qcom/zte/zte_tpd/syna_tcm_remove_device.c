__int64 __fastcall syna_tcm_remove_device(__int64 a1, __int64 a2, __int64 a3)
{
  void *v3; // x0
  __int64 v5; // x20
  __int64 v6; // x0
  __int64 v7; // x2
  __int64 v8; // x2
  __int64 v9; // x20
  __int64 v10; // x0
  __int64 v11; // x2
  __int64 v12; // x2
  __int64 v13; // x20
  __int64 v14; // x0
  __int64 v15; // x2
  __int64 v16; // x2
  __int64 v17; // x20
  __int64 v18; // x0
  __int64 v19; // x2
  __int64 v20; // x2
  __int64 v21; // x20
  __int64 v22; // x0
  __int64 v23; // x2
  __int64 v24; // x2
  __int64 v25; // x20
  __int64 v26; // x0
  __int64 v27; // x2
  __int64 v28; // x0
  __int64 v29; // x2

  if ( a1 )
  {
    if ( *(_BYTE *)(a1 + 784) )
      printk(unk_34845, "syna_tcm_buf_release", *(unsigned __int8 *)(a1 + 784));
    v5 = *(_QWORD *)(a1 + 720);
    v6 = syna_request_managed_device();
    if ( v6 )
    {
      if ( v5 )
        devm_kfree(v6, v5);
    }
    else
    {
      printk(unk_3BE43, "syna_pal_mem_free", v7);
    }
    v8 = *(unsigned __int8 *)(a1 + 712);
    *(_QWORD *)(a1 + 728) = 0;
    *(_BYTE *)(a1 + 784) = 0;
    if ( (_DWORD)v8 )
      printk(unk_34845, "syna_tcm_buf_release", v8);
    v9 = *(_QWORD *)(a1 + 648);
    v10 = syna_request_managed_device();
    if ( v10 )
    {
      if ( v9 )
        devm_kfree(v10, v9);
    }
    else
    {
      printk(unk_3BE43, "syna_pal_mem_free", v11);
    }
    v12 = *(unsigned __int8 *)(a1 + 640);
    *(_QWORD *)(a1 + 656) = 0;
    *(_BYTE *)(a1 + 712) = 0;
    if ( (_DWORD)v12 )
      printk(unk_34845, "syna_tcm_buf_release", v12);
    v13 = *(_QWORD *)(a1 + 576);
    v14 = syna_request_managed_device();
    if ( v14 )
    {
      if ( v13 )
        devm_kfree(v14, v13);
    }
    else
    {
      printk(unk_3BE43, "syna_pal_mem_free", v15);
    }
    v16 = *(unsigned __int8 *)(a1 + 464);
    *(_QWORD *)(a1 + 584) = 0;
    *(_BYTE *)(a1 + 640) = 0;
    if ( (_DWORD)v16 )
      printk(unk_34845, "syna_tcm_buf_release", v16);
    v17 = *(_QWORD *)(a1 + 400);
    v18 = syna_request_managed_device();
    if ( v18 )
    {
      if ( v17 )
        devm_kfree(v18, v17);
    }
    else
    {
      printk(unk_3BE43, "syna_pal_mem_free", v19);
    }
    v20 = *(unsigned __int8 *)(a1 + 320);
    *(_QWORD *)(a1 + 408) = 0;
    *(_BYTE *)(a1 + 464) = 0;
    if ( (_DWORD)v20 )
      printk(unk_34845, "syna_tcm_buf_release", v20);
    v21 = *(_QWORD *)(a1 + 256);
    v22 = syna_request_managed_device();
    if ( v22 )
    {
      if ( v21 )
        devm_kfree(v22, v21);
    }
    else
    {
      printk(unk_3BE43, "syna_pal_mem_free", v23);
    }
    v24 = *(unsigned __int8 *)(a1 + 392);
    *(_QWORD *)(a1 + 264) = 0;
    *(_BYTE *)(a1 + 320) = 0;
    if ( (_DWORD)v24 )
      printk(unk_34845, "syna_tcm_buf_release", v24);
    v25 = *(_QWORD *)(a1 + 328);
    v26 = syna_request_managed_device();
    if ( v26 )
    {
      if ( v25 )
        devm_kfree(v26, v25);
    }
    else
    {
      printk(unk_3BE43, "syna_pal_mem_free", v27);
    }
    *(_QWORD *)(a1 + 336) = 0;
    *(_BYTE *)(a1 + 392) = 0;
    *(_QWORD *)a1 = 0;
    *(_QWORD *)(a1 + 72) = 0;
    v28 = syna_request_managed_device();
    if ( v28 )
      devm_kfree(v28, a1);
    else
      printk(unk_3BE43, "syna_pal_mem_free", v29);
    v3 = unk_3AC8E;
  }
  else
  {
    v3 = unk_3365A;
  }
  return printk(v3, "syna_tcm_remove_device", a3);
}
