__int64 __fastcall gpio_keys_open(__int64 a1)
{
  _QWORD *v1; // x21
  __int64 v2; // x8
  __int64 (__fastcall *v3)(_QWORD); // x9
  __int64 v4; // x0
  __int64 result; // x0
  __int64 v6; // x19
  __int64 v7; // x22
  _QWORD *v8; // x20

  v1 = *(_QWORD **)(a1 + 712);
  v2 = *v1;
  v3 = *(__int64 (__fastcall **)(_QWORD))(*v1 + 24LL);
  if ( !v3 )
    goto LABEL_6;
  v4 = *(_QWORD *)(a1 + 656);
  if ( *((_DWORD *)v3 - 1) != 711998475 )
    __break(0x8229u);
  result = v3(v4);
  if ( !(_DWORD)result )
  {
    v2 = *v1;
LABEL_6:
    v6 = v1[1];
    if ( *(int *)(v2 + 8) >= 1 )
    {
      v7 = 0;
      v8 = v1 + 9;
      do
      {
        if ( v8[2] )
        {
          gpio_keys_gpio_report_event(v8);
          v2 = *v1;
        }
        ++v7;
        v8 += 34;
      }
      while ( v7 < *(int *)(v2 + 8) );
    }
    input_event(v6, 0, 0, 0);
    return 0;
  }
  return result;
}
