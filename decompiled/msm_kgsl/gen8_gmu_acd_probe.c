unsigned __int64 __fastcall gen8_gmu_acd_probe(unsigned __int64 result, __int64 a2)
{
  unsigned int v2; // w11
  unsigned int v3; // w13
  int v4; // w8
  unsigned __int64 v5; // x9
  unsigned int v6; // w10
  _DWORD *v7; // x12
  unsigned __int64 v8; // x19

  v2 = *(_DWORD *)(result + 10068) - 1;
  if ( v2 >= 0x21 )
  {
LABEL_14:
    __break(0x5512u);
    return gen8_gmu_irq_handler();
  }
  else if ( (*(_BYTE *)(*(_QWORD *)(result + 14264) + 33LL) & 1) != 0 )
  {
    *(_QWORD *)(a2 + 704) = 0x100000000LL;
    *(_QWORD *)(a2 + 696) = 0x100000007LL;
    v3 = *(_DWORD *)(result + 10068);
    if ( v3 )
    {
      v4 = 0;
      v5 = 0;
      v6 = 0;
      v7 = (_DWORD *)(result + 28LL * v2 + 9160);
      do
      {
        if ( *v7 )
        {
          v4 |= 2 << v6;
          *(_DWORD *)(a2 + 704) = v4;
          if ( v5 > 0x3F )
            goto LABEL_14;
          *(_DWORD *)(a2 + 716 + 4 * v5++) = *v7;
          v3 = *(_DWORD *)(result + 10068);
        }
        ++v6;
        v7 -= 7;
      }
      while ( v6 < v3 );
      if ( v4 )
      {
        *(_DWORD *)(a2 + 712) = v5;
        v8 = result;
        result = qmp_get(*(_QWORD *)(result + 1544) + 16LL);
        *(_QWORD *)(a2 + 1016) = result;
        if ( result <= 0xFFFFFFFFFFFFF000LL )
          *(_BYTE *)(v8 + 20433) = 1;
        else
          return dev_err(*(_QWORD *)(v8 + 1544) + 16LL, "AOP qmp init failed: %d\n", result);
      }
    }
  }
  return result;
}
