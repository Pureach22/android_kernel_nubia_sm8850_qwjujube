__int64 __fastcall ft_pagefault_policy_store(__int64 a1, char a2)
{
  __int64 v4; // x20
  __int64 v5; // x8
  unsigned int (__fastcall *v6)(__int64, __int64); // x8

  rt_mutex_lock(a1 + 11088);
  v4 = a2 & 0xF;
  if ( *(_DWORD *)(a1 + 11120) != 2 )
    goto LABEL_7;
  v5 = *(_QWORD *)(a1 + 88);
  if ( !v5 )
    goto LABEL_7;
  v6 = *(unsigned int (__fastcall **)(__int64, __int64))(v5 + 64);
  if ( !v6 )
    goto LABEL_7;
  if ( *((_DWORD *)v6 - 1) != -1296958943 )
    __break(0x8228u);
  if ( !v6(a1 + 56, v4) )
LABEL_7:
    *(_QWORD *)(a1 + 112) = v4;
  rt_mutex_unlock(a1 + 11088);
  return 0;
}
