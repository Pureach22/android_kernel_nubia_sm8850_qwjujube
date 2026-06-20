__int64 __fastcall show_seg_size(const char **a1, __int64 a2, __int64 a3)
{
  const char *v4; // x0
  __int64 result; // x0
  __int64 v6; // [xsp+0h] [xbp-10h] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *a1;
  v6 = 0;
  if ( sscanf(v4, "segment%lu", &v6) == 1 )
  {
    result = (int)scnprintf(a3, 100, "%lu\n", *(_QWORD *)(segment_infos + 32 * v6 + 8));
  }
  else
  {
    printk(&unk_9D5B);
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
