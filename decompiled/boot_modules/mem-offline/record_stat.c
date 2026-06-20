unsigned __int64 __fastcall record_stat(unsigned __int64 result, unsigned __int64 a2, int a3)
{
  unsigned __int64 v4; // x19
  unsigned int v5; // w22
  __int64 v6; // x9
  __int64 v7; // x8
  __int64 v8; // x10
  unsigned __int64 *v9; // x10
  __int64 v10; // t1
  __int64 v11; // x10
  unsigned __int64 *v12; // x10
  unsigned __int64 v13; // t1
  unsigned __int64 *v14; // x10
  unsigned __int64 v15; // x13
  unsigned __int64 v16; // x11
  __int64 v17; // x25
  __int64 v18; // x8
  unsigned __int64 v19; // x9
  __int64 v20; // x8
  unsigned __int64 v21; // x11
  __int64 v22; // x9
  __int64 v23; // x8

  if ( end_section_nr >= result )
  {
    v4 = result;
    v5 = end_section_nr - start_section_nr + 1;
    v6 = mem_info;
    v7 = (unsigned int)((result - start_section_nr + v5 * a3) / (unsigned int)sections_per_block);
    v8 = mem_info + 72LL * (unsigned int)v7;
    v10 = *(_QWORD *)(v8 + 24);
    v9 = (unsigned __int64 *)(v8 + 24);
    if ( v10 - 1 >= a2 )
      *v9 = a2;
    v11 = v6 + 72LL * (unsigned int)v7;
    v13 = *(_QWORD *)(v11 + 32);
    v12 = (unsigned __int64 *)(v11 + 32);
    if ( v13 < a2 )
      *v12 = a2;
    v14 = (unsigned __int64 *)(v6 + 72LL * (unsigned int)v7);
    v15 = v14[1];
    v16 = *v14 + 1;
    *v14 = v16;
    if ( v15 )
      v14[1] = v15 - 1;
    v17 = 72 * v7;
    v18 = v6 + 72 * v7;
    v19 = *(_QWORD *)(v18 + 40) + a2;
    *(_QWORD *)(v18 + 40) = v19;
    *(_QWORD *)(v18 + 48) = a2;
    v14[2] = v19 / v16;
    result = ktime_get(result);
    v20 = mem_info;
    v21 = (unsigned int)sections_per_block;
    *(_QWORD *)(mem_info + v17 + 64) = result;
    if ( a3 )
      v22 = 0;
    else
      v22 = v5;
    v23 = v20 + 72LL * (unsigned int)((v22 + v4 - start_section_nr) / v21);
    *(_QWORD *)(v23 + 56) += result - *(_QWORD *)(v23 + 64);
    *(_QWORD *)(v23 + 64) = 0;
  }
  return result;
}
