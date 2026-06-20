__int64 __fastcall sde_dbg_dump_bus_entry(
        __int64 result,
        __int64 a2,
        int a3,
        __int64 a4,
        unsigned int *a5,
        char a6,
        unsigned int a7)
{
  __int64 v7; // x21
  int v10; // w10
  __int64 (__fastcall *v11)(__int64, __int64); // x8
  __int64 v12; // x1
  void (__fastcall *v13)(__int64, __int64); // x8
  unsigned int *v14; // x20
  __int64 v15; // x1
  unsigned int v16; // w9
  unsigned int v17; // w10
  unsigned int v18; // w8
  unsigned int v19; // w24
  unsigned int v20; // w26
  _DWORD *v21; // x8
  __int64 v22; // x1
  __int64 v23; // x2
  _DWORD *v24; // x8
  unsigned int v25; // w0
  const char *v26; // x25
  unsigned int v27; // w28
  unsigned int v28; // w27
  int v29; // w0
  unsigned int v30; // w25
  unsigned int v31; // w19
  __int64 v32; // x8
  int v33; // w9
  int v34; // w10
  _DWORD *v35; // x11
  unsigned int v36; // w12
  bool v37; // zf
  unsigned int v38; // w13
  int v39; // w11
  unsigned int v40; // w14
  bool v41; // cc
  bool v42; // cc
  unsigned int v43; // w11
  bool v44; // cc
  int v48; // [xsp+18h] [xbp-18h]
  int v49; // [xsp+20h] [xbp-10h]

  if ( *(_QWORD *)(result + 64) )
  {
    v7 = result;
    if ( *(_QWORD *)(result + 72) )
    {
      if ( a3 )
      {
        v10 = 0;
        v49 = a6 & 0xA;
        while ( 1 )
        {
          v48 = v10;
          v13 = *(void (__fastcall **)(__int64, __int64))(v7 + 80);
          v14 = (unsigned int *)(a2 + 32LL * v10);
          if ( v13 )
          {
            v15 = *v14;
            if ( *((_DWORD *)v13 - 1) != -1783303382 )
              __break(0x8228u);
            v13(a4, v15);
          }
          v16 = v14[2];
          v17 = v14[3];
          if ( v16 < v17 + v16 )
            break;
LABEL_5:
          v11 = *(__int64 (__fastcall **)(__int64, __int64))(v7 + 72);
          v12 = *v14;
          if ( *((_DWORD *)v11 - 1) != -1783303382 )
            __break(0x8228u);
          result = v11(a4, v12);
          v10 = v48 + 1;
          if ( v48 + 1 == a3 )
            return result;
        }
        v19 = v14[4];
        v18 = v14[5];
        v20 = v14[2];
        while ( v19 >= v18 + v19 )
        {
LABEL_15:
          if ( ++v20 >= v17 + v16 )
            goto LABEL_5;
        }
        while ( 1 )
        {
          v22 = *v14;
          v23 = v14[1];
          v24 = *(_DWORD **)(v7 + 64);
          if ( *(v24 - 1) != -658259135 )
            __break(0x8228u);
          v25 = ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD, _QWORD))v24)(a4, v22, v23, v20, v19);
          v26 = *(const char **)v7;
          v27 = *v14;
          v28 = v25;
          if ( !strcmp(*(const char **)v7, "vbif_rt") )
          {
            v30 = 1 << v20;
            v31 = v27;
            v21 = *((_DWORD **)v14 + 3);
            if ( v21 )
              goto LABEL_19;
          }
          else
          {
            v29 = strcmp(v26, "dsi");
            v30 = v20;
            v31 = v27;
            if ( a7 <= 1 && !v29 )
            {
              v30 = v20;
              v31 = dsi_block_offset[a7] + v27;
            }
            v21 = *((_DWORD **)v14 + 3);
            if ( v21 )
            {
LABEL_19:
              if ( *(v21 - 1) != -929320374 )
                __break(0x8228u);
              ((void (__fastcall *)(_QWORD, _QWORD, _QWORD, _QWORD))v21)(v31, v20, v19, v28);
              goto LABEL_22;
            }
          }
          if ( (a6 & 1) == 0 )
          {
            if ( (a6 & 4) == 0 )
              goto LABEL_51;
            v32 = *(_QWORD *)(v7 + 48);
            if ( v32 )
            {
              v33 = *(_DWORD *)(v7 + 12);
              if ( v33 )
              {
                v34 = 0;
                while ( 1 )
                {
                  v35 = (_DWORD *)(v32 + 32LL * v34);
                  v36 = v35[2];
                  v37 = *v35 == v27;
                  v38 = v35[3] + v36;
                  v40 = v35[4];
                  v39 = v35[5];
                  v41 = !v37 || v36 > v30;
                  v42 = !v41 && v38 > v30;
                  v43 = v39 + v40;
                  v44 = !v42 || v40 > v19;
                  if ( !v44 && v43 > v19 )
                    break;
                  if ( v33 == ++v34 )
                    goto LABEL_51;
                }
              }
            }
          }
          dev_err(qword_2942C8, "0x%08x| %08x %08x %08x %08x\n", 0, v31, v30, v19, v28);
          v21 = *((_DWORD **)v14 + 3);
          if ( v21 )
            goto LABEL_19;
LABEL_51:
          if ( a5 && v49 )
          {
            if ( (word_294380 & 0x100) == 0 )
            {
              *a5 = v31;
              a5[1] = v30;
              a5[2] = v19;
              a5[3] = v28;
              a5 += 4;
            }
            if ( (a6 & 8) != 0 && a5 && HIBYTE(word_294380) == 1 )
            {
              drm_printf(qword_2945A8, "0x%08x| %08x %08x %08x %08x\n", 0, *a5, a5[1], a5[2], a5[3]);
              a5 += 4;
            }
          }
LABEL_22:
          v18 = v14[5];
          if ( ++v19 >= v18 + v14[4] )
          {
            v16 = v14[2];
            v17 = v14[3];
            v19 = v14[4];
            goto LABEL_15;
          }
        }
      }
    }
  }
  return result;
}
