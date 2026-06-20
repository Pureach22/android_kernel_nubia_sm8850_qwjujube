__int64 __fastcall wsa884x_get_dev_num(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x8

  v2 = *(_QWORD *)(a1 + 128);
  if ( !v2 )
    return 4294967274LL;
  v3 = *(_QWORD *)(*(_QWORD *)(v2 + 24) + 152LL);
  if ( v3 )
  {
    *(_QWORD *)(a2 + 72) = *(unsigned __int8 *)(*(_QWORD *)(v3 + 16) + 64LL);
    return 0;
  }
  else
  {
    if ( (unsigned int)__ratelimit(&wsa884x_get_dev_num__rs, "wsa884x_get_dev_num") )
      printk(&unk_D284, "wsa884x_get_dev_num");
    return 4294967274LL;
  }
}
