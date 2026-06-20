__int64 __fastcall core_info_read(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x24
  __int64 v8; // x0
  __int64 v9; // x25
  __int64 v10; // x22
  unsigned int v11; // w0
  __int64 v12; // x23
  __int64 v13; // x23
  unsigned int v14; // w0
  __int64 v15; // x19

  v4 = *(_QWORD *)(a1 + 32);
  if ( v4 )
  {
    v8 = vzalloc_noprof(4096);
    if ( v8 )
    {
      v9 = v8 + 4096;
      v10 = v8;
      v11 = ((__int64 (*)(void))write_str)();
      v12 = v10 + v11 + (unsigned int)write_str(v10 + v11, 4096LL - v11, "FW version : %s\n", (const char *)(v4 + 3576));
      v13 = v12 + (unsigned int)write_str(v12, v9 - v12, "register_base: 0x%x\n", **(_QWORD **)(v4 + 3904));
      v14 = write_str(v13, v9 - v13, "irq: %u\n", *(_DWORD *)(*(_QWORD *)(v4 + 3904) + 8LL));
      v15 = simple_read_from_buffer(a2, a3, a4, v10, v13 + v14 - v10);
      vfree(v10);
      return v15;
    }
    else
    {
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_8C985, "err ", 0xFFFFFFFFLL, "codec", "core_info_read");
      return -12;
    }
  }
  else
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_83566, "err ", 0xFFFFFFFFLL, "codec", "core_info_read");
    return 0;
  }
}
