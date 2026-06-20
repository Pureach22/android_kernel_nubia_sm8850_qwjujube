__int64 __fastcall spf_core_callback(__int64 a1, unsigned int *a2)
{
  __int64 v3; // x21
  unsigned int v5; // w8
  _DWORD *v6; // x20
  unsigned __int64 v7; // x22
  int v8; // w8

  v3 = *(_QWORD *)(a1 + 152);
  if ( (unsigned int)__ratelimit(&spf_core_callback__rs, "spf_core_callback") )
    dev_info(a1, "%s: Payload %x", "spf_core_callback", a2[5]);
  v5 = a2[5];
  if ( v5 == 33558535 )
  {
    v7 = ((unsigned __int64)*a2 >> 2) & 0x3C;
    if ( (unsigned int)__ratelimit(&spf_core_callback__rs_34, "spf_core_callback") )
      dev_info(a1, "%s: sucess response received", "spf_core_callback");
    v8 = *(unsigned int *)((char *)a2 + v7);
    *(_BYTE *)(v3 + 80) = 1;
    *(_DWORD *)(v3 + 84) = v8;
  }
  else if ( v5 == 33558533 )
  {
    v6 = (unsigned int *)((char *)a2 + (((unsigned __int64)*a2 >> 2) & 0x3C));
    if ( (unsigned int)__ratelimit(&spf_core_callback__rs_30, "spf_core_callback") )
      dev_info(a1, "%s: op %x status %d", "spf_core_callback", *v6, v6[1]);
    if ( *v6 == 16781331 )
    {
      *(_DWORD *)(v3 + 84) = v6[1];
    }
    else if ( (unsigned int)__ratelimit(&spf_core_callback__rs_32, "spf_core_callback") )
    {
      dev_err(a1, "%s: Failed response received", "spf_core_callback");
    }
    *(_BYTE *)(v3 + 80) = 1;
  }
  else if ( (unsigned int)__ratelimit(&spf_core_callback__rs_36, "spf_core_callback") )
  {
    dev_err(a1, "Message ID from apm: 0x%x\n", a2[5]);
  }
  if ( *(_BYTE *)(v3 + 80) == 1 )
    _wake_up(v3 + 8, 3, 1, 0);
  return 0;
}
