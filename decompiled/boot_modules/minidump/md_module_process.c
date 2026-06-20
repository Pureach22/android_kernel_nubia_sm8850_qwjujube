__int64 __fastcall md_module_process(__int64 a1)
{
  unsigned __int64 v1; // x27
  __int64 v3; // x21
  char v4; // w20
  const char **v5; // x22
  const char *v6; // t1
  __int64 result; // x0
  __int64 v8; // x0
  unsigned __int64 v9; // x20
  unsigned __int64 v10; // x26
  __int64 v11; // x8
  unsigned int v12; // w22
  __int64 v13; // x9
  unsigned __int64 v14; // x3
  int v16; // w21
  __int64 v17; // x23
  __int64 v18; // x24
  char s[8]; // [xsp+8h] [xbp-18h] BYREF
  int v20; // [xsp+10h] [xbp-10h]
  __int64 v21; // [xsp+18h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = (unsigned int)n_modump;
  if ( n_modump < 1 )
  {
    v4 = 0;
  }
  else
  {
    if ( (unsigned int)(n_modump - 11) < 0xFFFFFFF6 )
    {
      __break(0x5512u);
      _WriteStatusReg(ARM64_SYSREG(3, 2, 7, 10, 1), v1);
      return md_module_notify();
    }
    v4 = 0;
    v5 = (const char **)&key_modules;
    do
    {
      v6 = *v5++;
      --v3;
      v4 |= strcmp(v6, (const char *)(a1 + 24)) == 0;
    }
    while ( v3 );
  }
  result = md_mod_info_seq_buf;
  if ( md_mod_info_seq_buf )
  {
    v8 = seq_buf_printf(
           md_mod_info_seq_buf,
           "name: %s, base: %lx, nplt: %d",
           (const char *)(a1 + 24),
           *(_QWORD *)(a1 + 448),
           *(_DWORD *)(a1 + 960) + 2);
    if ( (v4 & 1) != 0 )
    {
      v9 = *(_QWORD *)(a1 + 520);
      v10 = *(unsigned int *)(a1 + 528);
      if ( (int)msm_minidump_get_available_region(v8) <= v10 >> 12 )
      {
        printk(&unk_11327A, a1 + 24);
      }
      else
      {
        v11 = *(_QWORD *)(a1 + 1264);
        if ( *(_DWORD *)(v11 + 40) )
        {
          v12 = 0;
          do
          {
            v13 = v11 + 80LL * (int)v12;
            v14 = *(_QWORD *)(v13 + 120);
            if ( v14 >= v9 && v14 < v10 + v9 )
            {
              seq_buf_printf(md_mod_info_seq_buf, ", %s: %lx", *(const char **)(v13 + 48), v14);
              v11 = *(_QWORD *)(a1 + 1264);
            }
            ++v12;
          }
          while ( v12 < *(_DWORD *)(v11 + 40) );
        }
        if ( (_DWORD)v10 )
        {
          v16 = 0;
          v20 = 0;
          *(_QWORD *)s = 0;
          do
          {
            if ( v10 >= 4096 - (v9 & 0xFFF) )
              v17 = 4096 - (v9 & 0xFFF);
            else
              v17 = v10;
            v18 = ((vmalloc_to_page(v9) - -64LL * (memstart_addr >> 12)) << 6) + 0x5000000000LL;
            snprintf(s, 0xCu, "%d_%s", v16, (const char *)(a1 + 24));
            md_register_minidump_entry(s, v9, v18, v17);
            v10 -= v17;
            v9 += v17;
            ++v16;
          }
          while ( v10 );
        }
      }
    }
    result = seq_buf_printf(md_mod_info_seq_buf, "\n");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
