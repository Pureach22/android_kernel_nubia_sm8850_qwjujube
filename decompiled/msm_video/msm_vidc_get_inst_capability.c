__int64 __fastcall msm_vidc_get_inst_capability(__int64 a1)
{
  __int64 v1; // x23
  int v2; // w24
  int v4; // w8
  int v5; // w28
  _DWORD *v6; // x9
  __int64 v7; // x4

  v1 = *(_QWORD *)(a1 + 320);
  v2 = *(_DWORD *)(v1 + 3936) + *(_DWORD *)(v1 + 3932);
  if ( v2 )
  {
    v4 = 0;
    do
    {
      v5 = v4;
      v6 = (_DWORD *)(*(_QWORD *)(v1 + 4784) + 33272LL * v4);
      if ( *v6 == *(_DWORD *)(a1 + 308) )
      {
        v7 = (unsigned int)v6[1];
        if ( (_DWORD)v7 == *(_DWORD *)(a1 + 312) )
        {
          if ( a1 && (msm_vidc_debug & 2) != 0 )
            printk(&unk_9237C, "high", a1 + 340, "msm_vidc_get_inst_capability", v7);
          memcpy((void *)(a1 + 4320), (const void *)(*(_QWORD *)(v1 + 4784) + 33272LL * v5 + 8), 0x81F0u);
        }
      }
      v4 = v5 + 1;
    }
    while ( v2 != v5 + 1 );
  }
  return 0;
}
