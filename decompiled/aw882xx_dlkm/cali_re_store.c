__int64 __fastcall cali_re_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x21
  __int64 *v7; // x8
  __int64 v8; // x1

  v5 = *(_QWORD *)(*(_QWORD *)(a1 + 152) + 96LL);
  if ( (int)aw_cali_svc_set_devs_re_str(v5, a3) <= 0 )
  {
    v7 = *(__int64 **)(v5 + 112);
    v8 = v7[14];
    if ( !v8 )
      v8 = *v7;
    printk(&unk_23797, v8, "cali_re_store");
    return -1;
  }
  return a4;
}
