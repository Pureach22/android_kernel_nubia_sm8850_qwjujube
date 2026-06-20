__int64 synx_global_mem_init()
{
  __int64 result; // x0
  __int64 v1; // x4
  __int64 v2; // x5
  unsigned int v3; // w19
  void *v4; // x0
  __int64 v5; // x1
  __int64 v6; // x2
  __int64 v7; // x3
  char *v8; // x5
  __int64 v9; // x4
  void *s; // [xsp+8h] [xbp-18h] BYREF
  size_t n; // [xsp+10h] [xbp-10h]
  __int64 v12; // [xsp+18h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  s = nullptr;
  n = 0;
  result = get_global_partition_info(&s);
  if ( (_DWORD)result )
  {
    if ( (synx_debug & 1) != 0 )
    {
      v3 = result;
      printk(&unk_27022, &unk_29207, "synx_global_mem_init", 1326, v1, v2);
      result = v3;
    }
    goto LABEL_15;
  }
  v4 = memset(s, 0, (unsigned int)n);
  if ( (synx_debug & 8) != 0 )
  {
    v4 = (void *)printk(&unk_254C6, &unk_2A972, "synx_global_mem_init", 1332, s, (unsigned int)n);
    synx_gmem_0 = (__int64)s;
    v8 = (char *)s + 520;
    synx_gmem_1 = (__int64)s + 512;
    synx_gmem_2 = (__int64)s + 520;
    if ( (synx_debug & 8) != 0 )
    {
      v4 = (void *)printk(&unk_29A85, &unk_2A972, "synx_global_mem_init", 1339, s, v8);
      if ( HIDWORD(n) )
        v9 = HIDWORD(n);
      else
        v9 = 40;
      glcoredata_size = v9;
      if ( (synx_debug & 8) != 0 )
      {
        v4 = (void *)printk(&unk_25EC0, &unk_2A972, "synx_global_mem_init", 1342, v9, v8);
        v9 = (unsigned int)glcoredata_size;
      }
      goto LABEL_10;
    }
  }
  else
  {
    synx_gmem_0 = (__int64)s;
    synx_gmem_1 = (__int64)s + 512;
    synx_gmem_2 = (__int64)s + 520;
  }
  if ( HIDWORD(n) )
    v9 = HIDWORD(n);
  else
    v9 = 40;
  glcoredata_size = v9;
LABEL_10:
  if ( synx_gmem_2 + (unsigned __int64)(unsigned int)((_DWORD)v9 << 12) <= (unsigned __int64)s + (unsigned int)n )
  {
    result = synx_gmem_init((__int64)v4, v5, v6, v7, v9, (__int64)v8);
  }
  else
  {
    if ( (synx_debug & 1) != 0 )
      printk(&unk_2895C, &unk_29207, "synx_global_mem_init", 1346, v9, v8);
    result = 4294967274LL;
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
