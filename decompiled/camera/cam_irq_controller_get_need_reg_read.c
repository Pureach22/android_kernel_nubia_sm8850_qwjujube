__int64 __fastcall cam_irq_controller_get_need_reg_read(__int64 result, __int64 a2)
{
  __int64 v2; // x19
  int v3; // w8
  __int64 v4; // x27
  __int64 v5; // x20
  __int64 v6; // x22
  char v7; // w9
  unsigned __int64 v8; // x23
  __int64 v9; // [xsp+18h] [xbp-8h]

  if ( *(_DWORD *)(result + 24) )
  {
    v2 = result;
    v3 = 0;
    v4 = *(_DWORD *)(result + 64) & 0x1FFFLL;
    do
    {
      v5 = *(_QWORD *)(v2 + 32) + 112LL * v3;
      v6 = v3;
      v7 = 0;
      do
      {
        if ( ((-1LL << v7) & v4) == 0 )
          break;
        v8 = __clz(__rbit64((-1LL << v7) & v4));
        if ( ((*(_DWORD *)(v5 + 28) | *(_DWORD *)(*(_QWORD *)(v2 + 40) + 4 * v6)) & *(_DWORD *)(v5 + 56 + 4 * v8)) != 0 )
          *(_BYTE *)(a2 + v8) = 1;
        if ( (debug_mdl & 0x800000) != 0 && !debug_priority )
        {
          v9 = a2;
          result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                     3,
                     debug_mdl & 0x800000,
                     4,
                     "cam_irq_controller_get_need_reg_read",
                     1039,
                     "(%s) reg:%d dep:%d need_reg_read = %d force_rd_mask: 0x%x",
                     (const char *)v2,
                     v6,
                     v8,
                     *(unsigned __int8 *)(a2 + v8),
                     *(_DWORD *)(v5 + 28));
          a2 = v9;
        }
        v7 = v8 + 1;
      }
      while ( v8 < 0xC );
      v3 = v6 + 1;
    }
    while ( (unsigned int)(v6 + 1) < *(_DWORD *)(v2 + 24) );
  }
  return result;
}
