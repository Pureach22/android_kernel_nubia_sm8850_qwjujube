__int64 __fastcall wlan_hdd_update_survey_info(_QWORD *a1, __int64 a2, __int64 a3, int a4)
{
  __int64 v7; // x22
  __int64 v8; // x8
  int *v9; // x12
  int v10; // w8
  __int64 v11; // x14
  _DWORD *v12; // x9
  __int64 v13; // x11
  int v14; // w13
  int v15; // w15
  int *v16; // x12
  __int64 v17; // x14
  int v18; // w13
  int v19; // w15
  int *v20; // x12
  __int64 v21; // x14
  int v22; // w13
  int v23; // w15
  int *v24; // x12
  __int64 v25; // x14
  int v26; // w13
  int v27; // w15
  int *v28; // x12
  __int64 v29; // x14
  int v30; // w13
  int v31; // w15
  int *v32; // x12
  __int64 v33; // x13
  int v34; // w10
  int v35; // w14
  unsigned int v36; // w20
  char v37; // w10
  int v38; // w10
  int v39; // w11
  int v41; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v42; // [xsp+8h] [xbp-8h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a2 + 24);
  v8 = *(_QWORD *)(a2 + 52824);
  v41 = 0;
  sme_get_operation_channel(*(_QWORD *)(v7 + 16), &v41, *(unsigned __int8 *)(v8 + 8));
  mutex_lock(v7 + 1744);
  v9 = (int *)a1[41];
  v10 = v41;
  if ( v9 && v9[5] >= 1 )
  {
    v11 = 1;
    v12 = (_DWORD *)(*(_QWORD *)(v7 + 1736) + 100LL * a4);
    v13 = *(_QWORD *)v9;
    v14 = *(unsigned __int16 *)v12;
    while ( 1 )
    {
      v15 = *(_DWORD *)(v13 + 4);
      if ( v15 == v14 )
        break;
      if ( v11 < v9[5] )
      {
        v13 += 64;
        ++v11;
        if ( v15 != v14 )
          continue;
      }
      goto LABEL_7;
    }
  }
  else
  {
LABEL_7:
    v16 = (int *)a1[42];
    if ( v16 && v16[5] >= 1 )
    {
      v17 = 1;
      v12 = (_DWORD *)(*(_QWORD *)(v7 + 1736) + 100LL * a4);
      v13 = *(_QWORD *)v16;
      v18 = *(unsigned __int16 *)v12;
      while ( 1 )
      {
        v19 = *(_DWORD *)(v13 + 4);
        if ( v19 == v18 )
          break;
        if ( v17 < v16[5] )
        {
          ++v17;
          v13 += 64;
          if ( v19 != v18 )
            continue;
        }
        goto LABEL_13;
      }
    }
    else
    {
LABEL_13:
      v20 = (int *)a1[43];
      if ( v20 && v20[5] >= 1 )
      {
        v21 = 1;
        v12 = (_DWORD *)(*(_QWORD *)(v7 + 1736) + 100LL * a4);
        v13 = *(_QWORD *)v20;
        v22 = *(unsigned __int16 *)v12;
        while ( 1 )
        {
          v23 = *(_DWORD *)(v13 + 4);
          if ( v23 == v22 )
            break;
          if ( v21 < v20[5] )
          {
            ++v21;
            v13 += 64;
            if ( v23 != v22 )
              continue;
          }
          goto LABEL_19;
        }
      }
      else
      {
LABEL_19:
        v24 = (int *)a1[44];
        if ( v24 && v24[5] >= 1 )
        {
          v25 = 1;
          v12 = (_DWORD *)(*(_QWORD *)(v7 + 1736) + 100LL * a4);
          v13 = *(_QWORD *)v24;
          v26 = *(unsigned __int16 *)v12;
          while ( 1 )
          {
            v27 = *(_DWORD *)(v13 + 4);
            if ( v27 == v26 )
              break;
            if ( v25 < v24[5] )
            {
              ++v25;
              v13 += 64;
              if ( v27 != v26 )
                continue;
            }
            goto LABEL_25;
          }
        }
        else
        {
LABEL_25:
          v28 = (int *)a1[45];
          if ( v28 && v28[5] >= 1 )
          {
            v29 = 1;
            v12 = (_DWORD *)(*(_QWORD *)(v7 + 1736) + 100LL * a4);
            v13 = *(_QWORD *)v28;
            v30 = *(unsigned __int16 *)v12;
            while ( 1 )
            {
              v31 = *(_DWORD *)(v13 + 4);
              if ( v31 == v30 )
                break;
              if ( v29 < v28[5] )
              {
                ++v29;
                v13 += 64;
                if ( v31 != v30 )
                  continue;
              }
              goto LABEL_31;
            }
          }
          else
          {
LABEL_31:
            v32 = (int *)a1[46];
            if ( !v32 || v32[5] < 1 )
            {
              v36 = 0;
              goto LABEL_45;
            }
            v33 = 1;
            v12 = (_DWORD *)(*(_QWORD *)(v7 + 1736) + 100LL * a4);
            v13 = *(_QWORD *)v32;
            v34 = *(unsigned __int16 *)v12;
            while ( 1 )
            {
              v35 = *(_DWORD *)(v13 + 4);
              if ( v35 == v34 )
                break;
              v36 = 0;
              if ( v33 < v32[5] )
              {
                ++v33;
                v13 += 64;
                if ( v35 != v34 )
                  continue;
              }
              goto LABEL_45;
            }
          }
        }
      }
    }
  }
  *(_QWORD *)a3 = v13;
  v37 = v12[2];
  *(_DWORD *)(a3 + 64) = 0;
  *(_BYTE *)(a3 + 68) = v37;
  v38 = 0;
  v39 = v12[2];
  if ( v39 != -128 && v39 )
  {
    v38 = 1;
    *(_DWORD *)(a3 + 64) = 1;
  }
  if ( *v12 == v10 )
  {
    v38 |= 2u;
    *(_DWORD *)(a3 + 64) = v38;
  }
  v36 = 1;
  *(_QWORD *)(a3 + 8) = (unsigned int)v12[3];
  *(_QWORD *)(a3 + 16) = (unsigned int)v12[4];
  *(_QWORD *)(a3 + 40) = (unsigned int)v12[5];
  *(_DWORD *)(a3 + 64) = v38 | 0x4C;
LABEL_45:
  mutex_unlock(v7 + 1744);
  _ReadStatusReg(SP_EL0);
  return v36;
}
