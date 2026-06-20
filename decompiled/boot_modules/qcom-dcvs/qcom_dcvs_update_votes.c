__int64 __fastcall qcom_dcvs_update_votes(char *s2, __int64 a2, unsigned int a3, int a4)
{
  __int64 v4; // x21
  unsigned int v6; // w19
  __int64 v7; // x24
  unsigned __int64 v8; // x9
  unsigned int *v9; // x28
  __int64 v10; // x26
  __int64 v11; // x8
  __int64 v12; // x25
  unsigned int v13; // w22
  _QWORD *v14; // x19
  int v15; // w26
  unsigned int v16; // w27
  char v17; // w21
  unsigned int v18; // w8
  __int64 v19; // x8
  int v20; // w9
  __int64 v21; // x8
  int v22; // w11
  unsigned int v23; // w10
  int v24; // w8
  __int64 (__fastcall *v25)(__int64, __int64 *, __int64); // x8
  int v26; // w0
  __int64 v27; // x25
  __int64 v28; // x23
  unsigned int v29; // w22
  __int64 v30; // x26
  unsigned int *v31; // x19
  __int64 v32; // x24
  __int64 v33; // x8
  __int64 v34; // x8
  unsigned int v35; // w11
  int v36; // w9
  __int64 v37; // x8
  int v38; // w12
  unsigned int v39; // w10
  int v40; // w8
  __int64 v41; // x26
  __int64 v42; // x24
  unsigned __int64 v43; // x27
  unsigned int *v44; // x28
  __int64 v45; // x22
  __int64 v46; // x8
  __int64 v47; // x23
  __int64 v48; // x9
  unsigned int v49; // w12
  int v50; // w11
  __int64 v51; // x10
  int v52; // w13
  unsigned int v53; // w9
  __int64 v54; // x10
  __int64 (__fastcall *v55)(__int64, __int64 *, __int64); // x8
  _DWORD *v56; // x8
  unsigned __int64 v58; // [xsp+18h] [xbp-58h]
  __int64 v60; // [xsp+28h] [xbp-48h] BYREF
  __int64 v61; // [xsp+30h] [xbp-40h]
  __int64 v62; // [xsp+38h] [xbp-38h]
  __int64 v63; // [xsp+40h] [xbp-30h]
  __int64 v64; // [xsp+48h] [xbp-28h]
  __int64 v65; // [xsp+50h] [xbp-20h]
  __int64 v66; // [xsp+58h] [xbp-18h]
  int v67; // [xsp+60h] [xbp-10h]
  __int64 v68; // [xsp+68h] [xbp-8h]

  v4 = a2;
  v68 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a4 == 2 )
  {
    v6 = -22;
    if ( s2 && a2 && a3 )
    {
      v41 = *(unsigned int *)(_ReadStatusReg(SP_EL0) + 40);
      v42 = 0;
      v6 = 0;
      v43 = a3;
      LODWORD(v61) = 0;
      v60 = 0;
      do
      {
        if ( ((v43 >> v42) & 1) != 0 )
        {
          if ( !dcvs_data )
            goto LABEL_97;
          v44 = (unsigned int *)(v4 + 12 * v42);
          v45 = v44[2];
          if ( (unsigned int)v45 >= 5 )
LABEL_106:
            __break(0x5512u);
          v46 = *(_QWORD *)(dcvs_data + 8 * v45 + 96);
          if ( !v46
            || (v47 = *(_QWORD *)(v46 + 160)) == 0
            || *(_QWORD *)(v47 + 48) == 24
            || strcmp(*(const char **)(*(_QWORD *)(v47 + 48) - 24LL), s2) )
          {
LABEL_97:
            v6 = -22;
            break;
          }
          v48 = *(_QWORD *)(v47 + 16);
          v49 = *v44;
          if ( !*(_DWORD *)(v47 + 8) )
          {
            if ( *(_DWORD *)(v48 + 136) <= *v44 )
              v49 = *v44;
            else
              v49 = *(_DWORD *)(v48 + 136);
          }
          v50 = *(_DWORD *)(v48 + 120);
          v51 = *(_QWORD *)(v48 + 112);
          v52 = 0;
          if ( v50 )
          {
            while ( 1 )
            {
              v53 = *(_DWORD *)(v51 + 4LL * v52);
              if ( v49 <= v53 )
                break;
              if ( v50 == ++v52 )
                goto LABEL_91;
            }
          }
          else
          {
            v53 = 0;
          }
          if ( v52 == v50 )
LABEL_91:
            v53 = *(_DWORD *)(v51 + 4LL * (unsigned int)(v50 - 1));
          v54 = *(_QWORD *)(v47 + 40);
          LODWORD(v60) = v53;
          LODWORD(v61) = v45;
          if ( v53 != *(_DWORD *)(v54 + 4 * v41) )
          {
            v55 = *(__int64 (__fastcall **)(__int64, __int64 *, __int64))(v47 + 128);
            if ( *((_DWORD *)v55 - 1) != -556726186 )
              __break(0x8228u);
            v6 = v55(v47, &v60, 1);
            if ( (v6 & 0x80000000) != 0 )
              break;
          }
        }
        ++v42;
      }
      while ( v42 != 5 );
    }
  }
  else
  {
    if ( a4 == 1 )
    {
      v26 = -22;
      if ( s2 && a2 && a3 )
      {
        v27 = 0;
        v28 = 0;
        v29 = 0;
        v30 = a3;
        v67 = 0;
        v65 = 0;
        v66 = 0;
        v63 = 0;
        v64 = 0;
        v61 = 0;
        v62 = 0;
        _ReadStatusReg(SP_EL0);
        v60 = 0;
        do
        {
          if ( ((1LL << v27) & v30) != 0 )
          {
            if ( !dcvs_data )
              goto LABEL_97;
            v31 = (unsigned int *)(v4 + 12 * v27);
            v32 = v31[2];
            if ( (unsigned int)v32 >= 5 )
              goto LABEL_106;
            v33 = *(_QWORD *)(dcvs_data + 8 * v32 + 96);
            if ( !v33 )
              goto LABEL_97;
            v26 = -22;
            if ( v27 != v32 )
              goto LABEL_103;
            v28 = *(_QWORD *)(v33 + 152);
            if ( !v28 || *(_QWORD *)(v28 + 48) == 24 )
              goto LABEL_103;
            if ( strcmp(*(const char **)(*(_QWORD *)(v28 + 48) - 24LL), s2) )
              goto LABEL_97;
            v34 = *(_QWORD *)(v28 + 16);
            v35 = *v31;
            if ( !*(_DWORD *)(v28 + 8) )
            {
              if ( *(_DWORD *)(v34 + 136) <= *v31 )
                v35 = *v31;
              else
                v35 = *(_DWORD *)(v34 + 136);
            }
            v36 = *(_DWORD *)(v34 + 120);
            v37 = *(_QWORD *)(v34 + 112);
            v38 = 0;
            if ( v36 )
            {
              while ( 1 )
              {
                v39 = *(_DWORD *)(v37 + 4LL * v38);
                if ( v35 <= v39 )
                  break;
                if ( v36 == ++v38 )
                  goto LABEL_64;
              }
            }
            else
            {
              v39 = 0;
            }
            if ( v38 == v36 )
LABEL_64:
              v39 = *(_DWORD *)(v37 + 4LL * (unsigned int)(v36 - 1));
            *((_DWORD *)&v60 + 3 * v27) = v39;
            if ( v39 == *(_DWORD *)(v28 + 24) )
              v40 = 0;
            else
              v40 = 1LL << v27;
            v29 |= v40;
          }
          ++v27;
        }
        while ( v27 != 5 );
        if ( !v29 )
        {
          v6 = 0;
          goto LABEL_104;
        }
        v56 = *(_DWORD **)(v28 + 128);
        if ( *(v56 - 1) != -556726186 )
          __break(0x8228u);
        v26 = ((__int64 (__fastcall *)(__int64, __int64 *, _QWORD))v56)(v28, &v60, v29);
      }
LABEL_103:
      v6 = v26;
      goto LABEL_104;
    }
    v6 = -22;
    if ( !a4 && s2 && a2 && a3 )
    {
      v7 = 0;
      v6 = 0;
      v8 = a3;
      LODWORD(v61) = 0;
      v60 = 0;
      _ReadStatusReg(SP_EL0);
      v58 = a3;
      do
      {
        if ( ((v8 >> v7) & 1) != 0 )
        {
          if ( !dcvs_data )
            goto LABEL_97;
          v9 = (unsigned int *)(v4 + 12 * v7);
          v10 = v9[2];
          if ( (unsigned int)v10 >= 5 )
            goto LABEL_106;
          v11 = *(_QWORD *)(dcvs_data + 8 * v10 + 96);
          if ( !v11 )
            goto LABEL_97;
          v12 = *(_QWORD *)(v11 + 144);
          if ( !v12 )
            goto LABEL_97;
          v13 = v6;
          mutex_lock(v12 + 72);
          v60 = 0;
          v14 = *(_QWORD **)(v12 + 48);
          LODWORD(v61) = v10;
          if ( v14 == (_QWORD *)(v12 + 48) )
            goto LABEL_98;
          v15 = 0;
          v16 = 0;
          v17 = 0;
          do
          {
            if ( !strcmp((const char *)*(v14 - 3), s2) )
            {
              v18 = *v9;
              v17 = 1;
              *((_DWORD *)v14 - 4) = *v9;
              *((_DWORD *)v14 - 3) = v9[1];
              v16 = v60;
              v15 = HIDWORD(v60);
            }
            else
            {
              v18 = *((_DWORD *)v14 - 4);
            }
            if ( v18 > v16 )
              v16 = v18;
            LODWORD(v60) = v16;
            v15 += *((_DWORD *)v14 - 3);
            HIDWORD(v60) = v15;
            v14 = (_QWORD *)*v14;
          }
          while ( v14 != (_QWORD *)(v12 + 48) );
          if ( (v17 & 1) == 0 )
          {
LABEL_98:
            mutex_unlock(v12 + 72);
            v6 = -22;
            break;
          }
          v19 = *(_QWORD *)(v12 + 16);
          if ( !*(_DWORD *)(v12 + 8) && *(_DWORD *)(v19 + 136) > v16 )
            v16 = *(_DWORD *)(v19 + 136);
          v20 = *(_DWORD *)(v19 + 120);
          v21 = *(_QWORD *)(v19 + 112);
          v6 = v13;
          v22 = 0;
          if ( v20 )
          {
            v4 = a2;
            while ( 1 )
            {
              v23 = *(_DWORD *)(v21 + 4LL * v22);
              if ( v16 <= v23 )
                break;
              if ( v20 == ++v22 )
                goto LABEL_33;
            }
          }
          else
          {
            v4 = a2;
            v23 = 0;
          }
          if ( v22 == v20 )
LABEL_33:
            v23 = *(_DWORD *)(v21 + 4LL * (unsigned int)(v20 - 1));
          v24 = *(_DWORD *)(v12 + 24);
          LODWORD(v60) = v23;
          if ( v23 != v24 || v15 != *(_DWORD *)(v12 + 28) )
          {
            v25 = *(__int64 (__fastcall **)(__int64, __int64 *, __int64))(v12 + 128);
            if ( *((_DWORD *)v25 - 1) != -556726186 )
              __break(0x8228u);
            v6 = v25(v12, &v60, 1);
          }
          mutex_unlock(v12 + 72);
          if ( (v6 & 0x80000000) != 0 )
            break;
          v8 = v58;
        }
        ++v7;
      }
      while ( v7 != 5 );
    }
  }
LABEL_104:
  _ReadStatusReg(SP_EL0);
  return v6;
}
