__int64 __fastcall cache_allocation_configure(__int64 a1)
{
  unsigned int partition; // w0
  __int64 result; // x0
  void *v4; // x8
  unsigned int v5; // w19
  void *v6; // x0
  int v7; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+18h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = 0;
  partition = msc_system_get_partition(2, &msc_queries, &v7);
  if ( (partition & 0x80000000) != 0 )
  {
    v4 = &unk_AC2F;
LABEL_7:
    v5 = partition;
    v6 = v4;
LABEL_9:
    printk(v6, "cache_allocation_configure", v5);
    result = v5;
    goto LABEL_4;
  }
  partition = msc_system_set_partition(2, &msc_queries, *(_QWORD *)(a1 + 64));
  if ( (partition & 0x80000000) != 0 )
  {
    v4 = &unk_ADCF;
    goto LABEL_7;
  }
  result = msc_system_set_partition(2, &unk_D40, *(_QWORD *)(a1 + 64) + 4LL);
  if ( (result & 0x80000000) != 0 )
  {
    v5 = result;
    msc_system_set_partition(2, &msc_queries, &v7);
    v6 = &unk_ABB7;
    goto LABEL_9;
  }
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}
