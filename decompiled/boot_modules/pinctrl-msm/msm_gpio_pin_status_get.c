__int64 __fastcall msm_gpio_pin_status_get(
        __int64 a1,
        __int64 a2,
        _DWORD *a3,
        int *a4,
        int *a5,
        int *a6,
        _DWORD *a7,
        _DWORD *a8)
{
  __int64 v8; // x27
  unsigned int v17; // w0
  __int64 v18; // x8
  unsigned int v19; // w27
  __int64 result; // x0
  unsigned __int64 v21; // x9
  char v22; // w8

  v8 = a1 + 976;
  v17 = readl((unsigned int *)(*(_QWORD *)(a1 + 976 + 8 * ((*(_QWORD *)(a2 + 84) >> 5) & 3LL))
                             + *(unsigned int *)(a2 + 60)));
  v18 = *(_QWORD *)(v8 + 8 * ((*(_QWORD *)(a2 + 84) >> 5) & 3LL));
  v19 = v17;
  result = readl((unsigned int *)(v18 + *(unsigned int *)(a2 + 64)));
  *a3 = ((unsigned __int64)v19 >> ((*(_QWORD *)(a2 + 84) >> 42) & 0x1F)) & 1;
  *a4 = (v19 >> (*(_DWORD *)(a2 + 84) >> 7)) & 7;
  *a5 = (v19 >> (*(_DWORD *)(a2 + 84) >> 17)) & 7;
  *a6 = (v19 >> (*(_DWORD *)(a2 + 84) >> 12)) & 3;
  *a7 = 0;
  if ( *(_DWORD *)(*(_QWORD *)(a1 + 968) + 112LL) )
  {
    v21 = *(_QWORD *)(a2 + 84);
    if ( ((v19 >> ((v21 >> 37) & 0x1F)) & 1) != 0 )
      *a7 = (((unsigned __int64)v19 >> (BYTE4(v21) & 0x1F)) & 1) == 0;
  }
  v22 = 52;
  if ( !*a3 )
    v22 = 47;
  *a8 = ((unsigned __int64)(unsigned int)result >> ((*(_QWORD *)(a2 + 84) >> v22) & 0x1F)) & 1;
  return result;
}
