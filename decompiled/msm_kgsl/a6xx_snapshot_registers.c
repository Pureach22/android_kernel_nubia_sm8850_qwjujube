__int64 __fastcall a6xx_snapshot_registers(_QWORD *a1, _DWORD *a2, unsigned __int64 a3, __int64 *a4)
{
  _QWORD *v4; // x19
  __int64 result; // x0
  int v6; // w10
  __int64 v7; // x9
  _QWORD *v8; // x19
  _DWORD *v9; // x20
  unsigned __int64 v10; // x21
  unsigned __int64 v11; // x12
  __int64 v12; // x8
  int v13; // w19
  _DWORD *v14; // x11
  unsigned __int64 v15; // x9
  int *v16; // x10
  unsigned int v17; // w13
  unsigned int v18; // w14
  unsigned __int64 v19; // x15
  bool v20; // cf
  int v21; // t1
  _QWORD *v22; // x21
  _DWORD *v23; // x20
  __int64 v25; // [xsp+8h] [xbp-18h] BYREF
  int v26; // [xsp+10h] [xbp-10h]
  int v27; // [xsp+14h] [xbp-Ch]
  __int64 v28; // [xsp+18h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (crash_dump_valid & 1) != 0 )
  {
    if ( a3 > 3 )
    {
      v11 = *((unsigned int *)a4 + 2);
      if ( (_DWORD)v11 )
      {
        v12 = 0;
        v13 = 0;
        v14 = a2 + 1;
        v15 = a3 - 4;
        v16 = (int *)(*(_QWORD *)(a6xx_crashdump_registers + 8) + a4[3]);
        while ( 1 )
        {
          v17 = *(_DWORD *)(*a4 + 4LL * (unsigned int)(2 * v12));
          v18 = *(_DWORD *)(*a4 + 4LL * ((2 * (_DWORD)v12) | 1u));
          v19 = 8 * (v18 - v17) + 8;
          v20 = v15 >= v19;
          v15 -= v19;
          if ( !v20 )
            break;
          if ( v18 >= v17 )
          {
            do
            {
              *v14 = v17++;
              ++v13;
              v21 = *v16++;
              v14[1] = v21;
              v14 += 2;
            }
            while ( v17 <= v18 );
            v11 = *((unsigned int *)a4 + 2);
          }
          if ( ++v12 >= v11 )
            goto LABEL_21;
        }
        v22 = a1;
        v23 = a2;
        if ( (unsigned int)__ratelimit(&a6xx_snapshot_registers__rs_10, "a6xx_snapshot_registers") )
          dev_err(*v22, "snapshot: not enough snapshot memory for section %s\n", "REGISTERS");
        a2 = v23;
      }
      else
      {
        v13 = 0;
      }
LABEL_21:
      *a2 = v13;
      result = (8 * v13) | 4u;
    }
    else
    {
      v4 = a1;
      if ( (unsigned int)__ratelimit(&a6xx_snapshot_registers__rs, "a6xx_snapshot_registers") )
        dev_err(*v4, "snapshot: not enough snapshot memory for section %s\n", "REGISTERS");
      result = 0;
    }
  }
  else
  {
    v6 = *((_DWORD *)a4 + 2);
    v7 = a4[2];
    v25 = *a4;
    v26 = v6;
    v27 = 0;
    if ( v7 )
    {
      v8 = a1;
      v9 = a2;
      v10 = a3;
      kgsl_regmap_write(a1 + 1650, *(unsigned int *)(v7 + 8));
      a3 = v10;
      a1 = v8;
      a2 = v9;
    }
    result = kgsl_snapshot_dump_registers(a1, a2, a3, &v25);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
