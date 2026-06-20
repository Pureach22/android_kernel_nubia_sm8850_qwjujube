__int64 __fastcall cam_vfe_bus_ver3_deinit_hw(__int64 a1)
{
  __int64 v1; // x19
  __int64 v3; // x9
  __int64 v4; // x8
  __int64 v5; // x11
  __int64 v6; // x10
  __int64 v7; // x12
  __int64 v8; // x0
  _QWORD *v9; // x1

  if ( a1 )
  {
    v1 = a1 + 0x8000;
    if ( *(_BYTE *)(a1 + 34666) == 1 )
    {
      v3 = raw_spin_lock_irqsave(a1 + 34560);
      v4 = a1;
      v5 = 0;
      v6 = v1 + 1776;
      *(_QWORD *)(v1 + 1776) = v1 + 1776;
      *(_QWORD *)(v1 + 1784) = v1 + 1776;
      do
      {
        v7 = v4 + v5;
        v8 = v7 + 1776;
        *(_QWORD *)(v7 + 1776) = v7 + 1776;
        *(_QWORD *)(v7 + 1784) = v7 + 1776;
        v9 = *(_QWORD **)(v1 + 1784);
        if ( (_QWORD *)(v4 + v5 + 1776) == v9 || *v9 != v6 )
        {
          _list_add_valid_or_report(v8);
          v4 = a1;
        }
        else
        {
          *(_QWORD *)(v1 + 1784) = v8;
          *(_QWORD *)(v7 + 1776) = v6;
          *(_QWORD *)(v7 + 1784) = v9;
          *v9 = v8;
        }
        v5 += 128;
      }
      while ( v5 != 0x8000 );
      *(_BYTE *)(v1 + 1898) = 0;
      raw_spin_unlock_irqrestore(v4 + 34560, v3);
    }
    return 0;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_ver3_deinit_hw",
      5268,
      "Error: Invalid args");
    return 4294967274LL;
  }
}
