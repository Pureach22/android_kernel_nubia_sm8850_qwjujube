__int64 __fastcall tpg_hw_apply_settings_to_hw_locked(unsigned int *a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x8
  unsigned int v6; // w9
  __int64 v7; // x8
  __int64 v8; // x9
  unsigned int v9; // w24
  int v10; // w25
  __int64 result; // x0
  unsigned int v12; // w23
  __int64 v13; // x22
  __int64 v14; // x9
  void (__fastcall *v15)(unsigned int *, __int64, __int64 *); // x8
  _QWORD *v16; // x8
  unsigned int v17; // w26
  __int64 v18; // x0
  _QWORD *v19; // x22
  _QWORD *v20; // x28
  __int64 v21; // x8
  unsigned int v22; // w27
  __int64 v23; // x8
  void (__fastcall *v24)(unsigned int *, __int64, unsigned __int64 *); // x8
  __int64 v25; // x9
  int v26; // w24
  __int64 v27; // x22
  __int64 v28; // x9
  void (__fastcall *v29)(unsigned int *, __int64, __int64 *); // x8
  _QWORD **v30; // x8
  _QWORD *v31; // x22
  unsigned int v32; // w26
  __int64 v33; // x0
  _QWORD *v34; // x22
  _QWORD *v35; // x28
  _QWORD *v36; // t1
  __int64 v37; // x8
  unsigned int v38; // w27
  __int64 v39; // x8
  void (__fastcall *v40)(unsigned int *, __int64, unsigned __int64 *); // x8
  __int64 v41; // x8
  __int64 (__fastcall *v42)(unsigned int *, __int64, __int64 *); // x8
  __int64 v43; // x0
  unsigned __int64 v44; // [xsp+8h] [xbp-38h] BYREF
  _QWORD *v45; // [xsp+10h] [xbp-30h]
  __int64 v46; // [xsp+18h] [xbp-28h] BYREF
  __int64 v47; // [xsp+20h] [xbp-20h]
  __int64 v48; // [xsp+28h] [xbp-18h] BYREF
  __int64 v49; // [xsp+30h] [xbp-10h]
  __int64 v50; // [xsp+38h] [xbp-8h]

  v50 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *((_QWORD *)a1 + 4);
  v48 = 0;
  v49 = 0;
  if ( v2 )
  {
    v3 = *(_QWORD *)(v2 + 16);
    if ( v3 )
    {
      if ( *(_QWORD *)(v3 + 48) && a2 && *((_QWORD *)a1 + 5) )
      {
        if ( !*(_DWORD *)(a2 + 8) )
        {
LABEL_40:
          result = 0;
          goto LABEL_12;
        }
        ((void (__fastcall *)(_QWORD, __int64))dump_global_configs)(*a1, a2 + 12);
        v6 = a1[1];
        v7 = *((_QWORD *)a1 + 4);
        if ( v6 == 1 )
        {
          if ( *(_DWORD *)(v7 + 4) )
          {
            v25 = *(_QWORD *)(a2 + 88);
            v12 = 0;
            v26 = 0;
            do
            {
              v46 = 0;
              v47 = 0;
              if ( *(_DWORD *)(v25 + 32LL * (int)v12 + 4) == -1 )
                break;
              v27 = 32LL * (int)v12;
              LODWORD(v46) = v12;
              v28 = v25 + v27;
              v29 = *(void (__fastcall **)(unsigned int *, __int64, __int64 *))(*(_QWORD *)(v7 + 16) + 48LL);
              HIDWORD(v46) = *(_DWORD *)(v28 + 8);
              v47 = *(_QWORD *)(v28 + 16) - 112LL;
              if ( *((_DWORD *)v29 - 1) != 150672744 )
                __break(0x8228u);
              v29(a1, 16385, &v46);
              v25 = *(_QWORD *)(a2 + 88);
              v30 = (_QWORD **)(v25 + v27 + 16);
              v31 = *v30;
              if ( *v30 != v30 )
              {
                v32 = 0;
                do
                {
                  v33 = *a1;
                  v36 = (_QWORD *)*v31;
                  v34 = v31 - 14;
                  v35 = v36;
                  v44 = 0;
                  v45 = nullptr;
                  ((void (__fastcall *)(__int64, _QWORD, _QWORD *))dump_stream_configs)(v33, v26 + v32, v34);
                  v37 = *((_QWORD *)a1 + 4);
                  v44 = __PAIR64__(v32, v12);
                  v38 = v32 + 1;
                  v39 = *(_QWORD *)(v37 + 16);
                  v45 = v34;
                  v40 = *(void (__fastcall **)(unsigned int *, __int64, unsigned __int64 *))(v39 + 48);
                  if ( *((_DWORD *)v40 - 1) != 150672744 )
                    __break(0x8228u);
                  v40(a1, 16386, &v44);
                  v25 = *(_QWORD *)(a2 + 88);
                  ++v32;
                  v31 = v35;
                }
                while ( v35 != (_QWORD *)(v25 + 32LL * (int)v12 + 16) );
                v26 += v38;
              }
              v7 = *((_QWORD *)a1 + 4);
              ++v12;
            }
            while ( v12 < *(_DWORD *)(v7 + 4) );
            goto LABEL_36;
          }
        }
        else if ( v6 == 3 && *(_DWORD *)(v7 + 4) )
        {
          v8 = *(_QWORD *)(a2 + 88);
          v9 = 0;
          v10 = 0;
          while ( 1 )
          {
            v46 = 0;
            v47 = 0;
            if ( *(_DWORD *)(v8 + 32LL * (int)v9 + 4) == -1 )
              break;
            v13 = 32LL * (int)v9;
            LODWORD(v46) = v9;
            v14 = v8 + v13;
            v15 = *(void (__fastcall **)(unsigned int *, __int64, __int64 *))(*(_QWORD *)(v7 + 16) + 48LL);
            HIDWORD(v46) = *(_DWORD *)(v14 + 8);
            v47 = *(_QWORD *)(v14 + 16) - 1160LL;
            if ( *((_DWORD *)v15 - 1) != 150672744 )
              __break(0x8228u);
            v15(a1, 16385, &v46);
            v8 = *(_QWORD *)(a2 + 88);
            v16 = *(_QWORD **)(v8 + v13 + 16);
            if ( v16 != (_QWORD *)(v8 + v13 + 16) )
            {
              v17 = 0;
              do
              {
                v18 = *a1;
                v19 = v16 - 145;
                v20 = (_QWORD *)*v16;
                v44 = 0;
                v45 = nullptr;
                ((void (__fastcall *)(__int64, _QWORD, _QWORD *))dump_stream_configs_v3)(v18, v10 + v17, v16 - 145);
                v21 = *((_QWORD *)a1 + 4);
                v44 = __PAIR64__(v17, v9);
                v22 = v17 + 1;
                v23 = *(_QWORD *)(v21 + 16);
                v45 = v19;
                v24 = *(void (__fastcall **)(unsigned int *, __int64, unsigned __int64 *))(v23 + 48);
                if ( *((_DWORD *)v24 - 1) != 150672744 )
                  __break(0x8228u);
                v24(a1, 16386, &v44);
                v8 = *(_QWORD *)(a2 + 88);
                ++v17;
                v16 = v20;
              }
              while ( v20 != (_QWORD *)(v8 + 32LL * (int)v9 + 16) );
              v10 += v22;
            }
            v7 = *((_QWORD *)a1 + 4);
            v12 = ++v9;
            if ( v9 >= *(_DWORD *)(v7 + 4) )
              goto LABEL_36;
          }
          v12 = v9;
          goto LABEL_36;
        }
        v12 = 0;
LABEL_36:
        v41 = *(_QWORD *)(v7 + 16);
        LODWORD(v48) = v12;
        v42 = *(__int64 (__fastcall **)(unsigned int *, __int64, __int64 *))(v41 + 48);
        v49 = a2 + 12;
        if ( *((_DWORD *)v42 - 1) != 150672744 )
          __break(0x8228u);
        v43 = v42(a1, 0x4000, &v48);
        if ( (cam_presil_mode_enabled(v43) & 1) == 0 )
          cam_tpg_mem_dmp(*((_QWORD *)a1 + 5), 0);
        goto LABEL_40;
      }
    }
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    0x200000000LL,
    1,
    "tpg_hw_apply_settings_to_hw_locked",
    460,
    "Invalid argument");
  result = 4294967274LL;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
