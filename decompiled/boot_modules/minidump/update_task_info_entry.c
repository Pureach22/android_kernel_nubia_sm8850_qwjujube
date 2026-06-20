__int64 __fastcall update_task_info_entry(__int64 a1)
{
  __int64 v2; // x9
  unsigned __int64 v3; // x10
  __int64 v4; // x9
  unsigned __int64 v5; // x13
  __int64 v6; // x10
  unsigned int v7; // w0
  __int64 v8; // x1
  __int64 v9; // x0
  __int64 v10; // x20
  __int64 v11; // x8
  __int64 v12; // x9
  unsigned __int64 v13; // x12
  __int64 v14; // x8
  __int64 v15; // x9
  unsigned int v16; // w0
  __int64 v17; // x1
  __int64 result; // x0
  __int64 v19; // x8
  unsigned int v20; // w19
  unsigned int v21; // w19
  _QWORD v22[3]; // [xsp+8h] [xbp-38h] BYREF
  __int64 v23; // [xsp+20h] [xbp-20h]
  __int64 v24; // [xsp+28h] [xbp-18h]
  __int64 v25; // [xsp+30h] [xbp-10h]
  __int64 v26; // [xsp+38h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v24 = 0;
  v25 = 0;
  v23 = 0;
  memset(v22, 0, sizeof(v22));
  scnprintf(v22, 13, "KRUNQUEUE");
  v23 = *(_QWORD *)md_runq_seq_buf;
  v2 = (__int64)(*(_QWORD *)md_runq_seq_buf << 8) >> 8;
  v3 = v2 + 0x8000000000LL;
  v4 = v2 - kimage_voffset;
  v5 = v3 >> 38;
  v6 = v3 + memstart_addr;
  if ( !v5 )
    v4 = v6;
  v24 = v4;
  v25 = *(_QWORD *)(md_runq_seq_buf + 8);
  v7 = msm_minidump_remove_region(v22);
  if ( (v7 & 0x80000000) != 0 )
  {
    v20 = v7;
    printk(&unk_112F45, v8);
    result = v20;
  }
  else
  {
    v9 = _kmalloc_noprof(a1, 3520);
    v10 = v9;
    if ( v9 )
    {
      v11 = v9 << 8 >> 8;
      v25 = a1;
      v12 = v11 + 0x8000000000LL;
      v13 = (unsigned __int64)(v11 + 0x8000000000LL) >> 38;
      v14 = v11 - kimage_voffset;
      v15 = memstart_addr + v12;
      if ( !v13 )
        v14 = v15;
      v23 = v9;
      v24 = v14;
      v16 = msm_minidump_add_region(v22);
      if ( (v16 & 0x80000000) != 0 )
      {
        v21 = v16;
        printk(&unk_11343D, v17);
        kfree(v10);
        result = v21;
      }
      else
      {
        kfree(*(_QWORD *)md_runq_seq_buf);
        result = 0;
        *(_QWORD *)md_runq_seq_buf = v10;
        v19 = md_runq_seq_buf;
        *(_QWORD *)(md_runq_seq_buf + 8) = a1;
        *(_QWORD *)(v19 + 16) = 0;
        if ( a1 )
          **(_BYTE **)v19 = 0;
      }
    }
    else
    {
      msm_minidump_add_region(v22);
      result = 4294967284LL;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
