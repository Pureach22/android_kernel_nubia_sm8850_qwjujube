__int64 __fastcall crm_set_hw_chn_switch_ctrl(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x20
  __int64 v3; // x21

  if ( *(_BYTE *)(*(_QWORD *)(result + 288) + 1LL) == 1 )
  {
    v1 = result;
    if ( *(int *)(result + 48) >= 1 )
    {
      v2 = 0;
      v3 = 0;
      do
      {
        result = writel_relaxed(
                   2u,
                   (unsigned int *)(*(_QWORD *)(*(_QWORD *)(v1 + 40) + v2 + 24)
                                  + (unsigned int)(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v1 + 40) + v2 + 40) + 8LL)
                                                 + *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v1 + 40) + v2 + 40) + 12LL)
                                                 * *(_DWORD *)(*(_QWORD *)(v1 + 40) + v2 + 32))));
        ++v3;
        v2 += 192;
      }
      while ( v3 < *(int *)(v1 + 48) );
    }
  }
  return result;
}
