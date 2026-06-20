__int64 __fastcall msm_data_fifo_config(__int64 a1, unsigned __int64 a2, int a3, unsigned __int8 a4)
{
  int v4; // w20
  _QWORD *v5; // x22
  unsigned __int64 v6; // x21
  __int64 v7; // x10
  int v9; // w8
  __int64 v10; // x20
  __int64 v11; // x21
  int v12; // w0

  v4 = a4;
  v5 = *(_QWORD **)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 152) + 368LL) + 96LL) + 152LL);
  if ( a4 >= 8u )
  {
    dev_err(*v5, "Invalid DBM EP num:%d\n", a4);
    return 4294967274LL;
  }
  else if ( *(unsigned __int8 *)(a1 + 170) >= 0x20uLL )
  {
    __break(0x5512u);
    return msm_dbm_write_ep_reg_field();
  }
  else
  {
    v6 = HIDWORD(a2);
    v7 = v5[62];
    LOBYTE(v5[5 * *(unsigned __int8 *)(a1 + 170) + 162]) = a4;
    writel((unsigned int)a2, v5[1] + *(_DWORD *)(v7 + 136) + *(_DWORD *)(v7 + 140) * (unsigned int)a4 + 1015808);
    writel(
      (unsigned int)v6,
      v5[1] + (unsigned int)(*(_DWORD *)(v5[62] + 144LL) + *(_DWORD *)(v5[62] + 148LL) * v4 + 1015808));
    v9 = *(_DWORD *)(v5[62] + 16LL) + *(_DWORD *)(v5[62] + 20LL) * v4;
    v10 = v5[1];
    v11 = (unsigned int)(v9 + 1015808);
    v12 = readl(v10 + v11);
    writel(v12 & 0xFFFF0000 | a3, v10 + v11);
    readl(v10 + v11);
    return 0;
  }
}
