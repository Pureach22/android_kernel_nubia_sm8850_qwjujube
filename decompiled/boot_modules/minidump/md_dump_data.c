__int64 __fastcall md_dump_data(__int64 result, const char *a2)
{
  __int64 v2; // x19
  unsigned __int16 v3; // w25
  unsigned int v4; // w26
  unsigned __int64 v5; // x23
  unsigned __int64 v6; // x23
  unsigned __int64 v7; // x23
  unsigned __int64 v8; // x23
  unsigned __int64 v9; // x23
  unsigned __int64 v10; // x23
  unsigned __int64 v11; // x23
  unsigned __int64 v12; // x23
  int v13; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (unsigned __int64)(result + 255) >= 0xFFFFFF80000000FFLL )
  {
    v2 = result;
    seq_buf_printf(md_cntxt_seq_buf, "\n%s: %#lx:\n", a2, result);
    v3 = v2 & 0xFFFC;
    v4 = ((unsigned int)(v2 & 3) + 287) >> 5;
    v5 = v2 & 0xFFFFFFFFFFFFFFFCLL;
    do
    {
      seq_buf_printf(md_cntxt_seq_buf, "%04lx ", v3);
      v13 = 0;
      if ( copy_from_kernel_nofault(&v13, v5, 4) )
        seq_buf_printf(md_cntxt_seq_buf, " ********");
      else
        seq_buf_printf(md_cntxt_seq_buf, " %08x", v13);
      v6 = v5 + 4;
      v13 = 0;
      if ( copy_from_kernel_nofault(&v13, v6, 4) )
        seq_buf_printf(md_cntxt_seq_buf, " ********");
      else
        seq_buf_printf(md_cntxt_seq_buf, " %08x", v13);
      v7 = v6 + 4;
      v13 = 0;
      if ( copy_from_kernel_nofault(&v13, v7, 4) )
        seq_buf_printf(md_cntxt_seq_buf, " ********");
      else
        seq_buf_printf(md_cntxt_seq_buf, " %08x", v13);
      v8 = v7 + 4;
      v13 = 0;
      if ( copy_from_kernel_nofault(&v13, v8, 4) )
        seq_buf_printf(md_cntxt_seq_buf, " ********");
      else
        seq_buf_printf(md_cntxt_seq_buf, " %08x", v13);
      v9 = v8 + 4;
      v13 = 0;
      if ( copy_from_kernel_nofault(&v13, v9, 4) )
        seq_buf_printf(md_cntxt_seq_buf, " ********");
      else
        seq_buf_printf(md_cntxt_seq_buf, " %08x", v13);
      v10 = v9 + 4;
      v13 = 0;
      if ( copy_from_kernel_nofault(&v13, v10, 4) )
        seq_buf_printf(md_cntxt_seq_buf, " ********");
      else
        seq_buf_printf(md_cntxt_seq_buf, " %08x", v13);
      v11 = v10 + 4;
      v13 = 0;
      if ( copy_from_kernel_nofault(&v13, v11, 4) )
        seq_buf_printf(md_cntxt_seq_buf, " ********");
      else
        seq_buf_printf(md_cntxt_seq_buf, " %08x", v13);
      v12 = v11 + 4;
      v13 = 0;
      if ( copy_from_kernel_nofault(&v13, v12, 4) )
        seq_buf_printf(md_cntxt_seq_buf, " ********");
      else
        seq_buf_printf(md_cntxt_seq_buf, " %08x", v13);
      result = seq_buf_printf(md_cntxt_seq_buf, "\n");
      --v4;
      v3 += 32;
      v5 = v12 + 4;
    }
    while ( v4 );
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
