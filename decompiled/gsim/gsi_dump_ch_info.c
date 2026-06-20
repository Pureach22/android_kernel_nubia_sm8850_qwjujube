long double __fastcall gsi_dump_ch_info(unsigned __int64 a1)
{
  long double result; // q0
  int reg_nk; // w0
  int v4; // w0
  int v5; // w0
  int v6; // w0
  int v7; // w0
  int v8; // w0
  int v9; // w0
  int v10; // w0
  __int64 v11; // x8
  int v12; // w0
  int v13; // w0
  int v14; // w0
  int v15; // w0
  int v16; // w0
  int v17; // w0
  int v18; // w0
  int v19; // w0
  int v20; // w0
  int v21; // w0
  int v22; // w0
  int v23; // w0
  int v24; // w0
  int v25; // w0

  if ( gsi_ctx )
  {
    if ( *(unsigned int *)(gsi_ctx + 28608) > a1 )
    {
      reg_nk = gsihal_read_reg_nk(8, *(unsigned int *)(gsi_ctx + 20), (unsigned int)a1);
      dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d CH%2lu CTX0  0x%x\n", "gsi_dump_ch_info", 3521, a1, reg_nk);
      v4 = gsihal_read_reg_nk(52, *(unsigned int *)(gsi_ctx + 20), (unsigned int)a1);
      dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d CH%2lu CTX1  0x%x\n", "gsi_dump_ch_info", 3524, a1, v4);
      v5 = gsihal_read_reg_nk(53, *(unsigned int *)(gsi_ctx + 20), (unsigned int)a1);
      dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d CH%2lu CTX2  0x%x\n", "gsi_dump_ch_info", 3527, a1, v5);
      v6 = gsihal_read_reg_nk(54, *(unsigned int *)(gsi_ctx + 20), (unsigned int)a1);
      dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d CH%2lu CTX3  0x%x\n", "gsi_dump_ch_info", 3530, a1, v6);
      v7 = gsihal_read_reg_nk(66, *(unsigned int *)(gsi_ctx + 20), (unsigned int)a1);
      dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d CH%2lu CTX4  0x%x\n", "gsi_dump_ch_info", 3533, a1, v7);
      v8 = gsihal_read_reg_nk(67, *(unsigned int *)(gsi_ctx + 20), (unsigned int)a1);
      dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d CH%2lu CTX5  0x%x\n", "gsi_dump_ch_info", 3536, a1, v8);
      v9 = gsihal_read_reg_nk(68, *(unsigned int *)(gsi_ctx + 20), (unsigned int)a1);
      dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d CH%2lu CTX6  0x%x\n", "gsi_dump_ch_info", 3539, a1, v9);
      v10 = gsihal_read_reg_nk(69, *(unsigned int *)(gsi_ctx + 20), (unsigned int)a1);
      dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d CH%2lu CTX7  0x%x\n", "gsi_dump_ch_info", 3542, a1, v10);
      v11 = gsi_ctx;
      if ( *(_DWORD *)(gsi_ctx + 16) >= 0xAu )
      {
        v12 = gsihal_read_reg_nk(70, *(unsigned int *)(gsi_ctx + 20), (unsigned int)a1);
        dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d CH%2lu CTX8  0x%x\n", "gsi_dump_ch_info", 3546, a1, v12);
        v11 = gsi_ctx;
      }
      v13 = gsihal_read_reg_nk(120, *(unsigned int *)(v11 + 20), (unsigned int)a1);
      dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d CH%2lu REFRP 0x%x\n", "gsi_dump_ch_info", 3550, a1, v13);
      v14 = gsihal_read_reg_nk(121, *(unsigned int *)(gsi_ctx + 20), (unsigned int)a1);
      dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d CH%2lu REFWP 0x%x\n", "gsi_dump_ch_info", 3553, a1, v14);
      v15 = gsihal_read_reg_nk(51, *(unsigned int *)(gsi_ctx + 20), (unsigned int)a1);
      dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d CH%2lu QOS   0x%x\n", "gsi_dump_ch_info", 3556, a1, v15);
      v16 = gsihal_read_reg_nk(56, *(unsigned int *)(gsi_ctx + 20), (unsigned int)a1);
      dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d CH%2lu SCR0  0x%x\n", "gsi_dump_ch_info", 3559, a1, v16);
      v17 = gsihal_read_reg_nk(57, *(unsigned int *)(gsi_ctx + 20), (unsigned int)a1);
      dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d CH%2lu SCR1  0x%x\n", "gsi_dump_ch_info", 3562, a1, v17);
      v18 = gsihal_read_reg_nk(58, *(unsigned int *)(gsi_ctx + 20), (unsigned int)a1);
      dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d CH%2lu SCR2  0x%x\n", "gsi_dump_ch_info", 3565, a1, v18);
      v19 = gsihal_read_reg_nk(59, *(unsigned int *)(gsi_ctx + 20), (unsigned int)a1);
      result = dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d CH%2lu SCR3  0x%x\n", "gsi_dump_ch_info", 3568, a1, v19);
      if ( *(_DWORD *)(gsi_ctx + 16) >= 0xAu )
      {
        v20 = gsihal_read_reg_nk(60, *(unsigned int *)(gsi_ctx + 20), (unsigned int)a1);
        dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d CH%2lu SCR4  0x%x\n", "gsi_dump_ch_info", 3572, a1, v20);
        v21 = gsihal_read_reg_nk(61, *(unsigned int *)(gsi_ctx + 20), (unsigned int)a1);
        dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d CH%2lu SCR5  0x%x\n", "gsi_dump_ch_info", 3575, a1, v21);
        v22 = gsihal_read_reg_nk(62, *(unsigned int *)(gsi_ctx + 20), (unsigned int)a1);
        dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d CH%2lu SCR6  0x%x\n", "gsi_dump_ch_info", 3578, a1, v22);
        v23 = gsihal_read_reg_nk(63, *(unsigned int *)(gsi_ctx + 20), (unsigned int)a1);
        dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d CH%2lu SCR7  0x%x\n", "gsi_dump_ch_info", 3581, a1, v23);
        v24 = gsihal_read_reg_nk(64, *(unsigned int *)(gsi_ctx + 20), (unsigned int)a1);
        dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d CH%2lu SCR8  0x%x\n", "gsi_dump_ch_info", 3584, a1, v24);
        v25 = gsihal_read_reg_nk(65, *(unsigned int *)(gsi_ctx + 20), (unsigned int)a1);
        return dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d CH%2lu SCR9  0x%x\n", "gsi_dump_ch_info", 3587, a1, v25);
      }
    }
  }
  else
  {
    printk(&unk_2DEB9, "gsi_dump_ch_info", 3510);
  }
  return result;
}
