__int64 __fastcall sde_encoder_misr_sign_event_notify(__int64 result)
{
  __int64 v1; // x21
  __int64 v2; // x8
  __int64 v3; // x19
  __int64 v4; // x25
  int v5; // w8
  unsigned __int64 v7; // x22
  _QWORD *v8; // x23
  unsigned __int64 v14; // x8
  unsigned __int64 v15; // x9
  __int64 (*v16)(void); // x8
  __int64 v17; // x8
  __int64 v18; // x10
  __int64 v19; // x12
  char v20; // w9
  __int64 v21; // x10
  __int64 v22; // x15
  unsigned __int16 *v23; // x14
  unsigned __int16 *v24; // x15
  __int64 v25; // x10
  __int64 v26; // x12
  __int64 v27; // x13
  __int64 v28; // x10
  __int64 v29; // x8
  __int64 v30; // x12
  __int64 v31; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v32[2]; // [xsp+10h] [xbp-10h] BYREF

  v32[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v32[0] = 0;
  if ( result )
  {
    v31 = 0;
    v1 = result;
    if ( *(_DWORD *)(result + 800) )
    {
      v2 = *(_QWORD *)(result + 328);
      if ( v2 )
      {
        v3 = *(_QWORD *)(v2 + 8);
        if ( v3 )
        {
          v4 = *(_QWORD *)(v3 + 2512);
          *(_QWORD *)(v3 + 5024) = 0;
          v5 = *(_DWORD *)(result + 196);
          _X20 = (unsigned __int64 *)(v3 + 5024);
          if ( v5 )
          {
            v7 = 0;
            v8 = v32;
            do
            {
              if ( v7 == 4 )
                goto LABEL_48;
              result = *(_QWORD *)(v1 + 200 + 8 * v7);
              if ( result && (v16 = *(__int64 (**)(void))(result + 208)) != nullptr )
              {
                if ( v7 == 3 )
                  goto LABEL_48;
                if ( *((_DWORD *)v16 - 1) != 1336452942 )
                  __break(0x8228u);
                result = v16();
                if ( (_DWORD)result )
                {
                  result = printk(&unk_21984E, "sde_encoder_misr_sign_event_notify");
                  goto LABEL_44;
                }
                __asm { PRFM            #0x11, [X20] }
                do
                  v14 = __ldxr(_X20);
                while ( __stxr(v14 + 1, _X20) );
              }
              else if ( (_drm_debug & 4) != 0 )
              {
                result = _drm_dev_dbg(0, 0, 0, "invalid misr ops idx:%d\n", v7);
              }
              v15 = *(unsigned int *)(v1 + 196);
              ++v7;
              v8 = (_QWORD *)((char *)v8 + 4);
            }
            while ( v7 < v15 );
            if ( (_DWORD)v15 )
            {
              v17 = *(_QWORD *)(v3 + 5104);
              _ZF = v17 == LODWORD(v32[0]);
              v5 = v17 != LODWORD(v32[0]);
              if ( !_ZF )
              {
                *(_QWORD *)(v3 + 5104) = LODWORD(v32[0]);
                LODWORD(v15) = *(_DWORD *)(v1 + 196);
              }
              if ( (unsigned int)v15 >= 2 )
              {
                if ( *(_QWORD *)(v3 + 5112) != HIDWORD(v32[0]) )
                {
                  *(_QWORD *)(v3 + 5112) = HIDWORD(v32[0]);
                  v5 = 1;
                  LODWORD(v15) = *(_DWORD *)(v1 + 196);
                }
                if ( (unsigned int)v15 > 2 )
LABEL_48:
                  __break(0x5512u);
              }
            }
            else
            {
              v5 = 0;
            }
          }
          v18 = *(unsigned int *)(v3 + 5032);
          if ( (_DWORD)v18 != *(_DWORD *)(v4 + 2048) )
            goto LABEL_42;
          if ( !(_DWORD)v18 )
            goto LABEL_45;
          if ( (unsigned int)(v18 - 5) < 0xFFFFFFFC )
            goto LABEL_48;
          v19 = 0;
          v20 = 0;
          v21 = -v18;
LABEL_35:
          v22 = 8 * v19++;
          v23 = (unsigned __int16 *)(v4 + 2058 + v22);
          v24 = (unsigned __int16 *)(v3 + 5042 + v22);
          do
          {
            if ( *(v24 - 3) != *(v23 - 3) || *(v24 - 1) != *(v23 - 1) || *(v24 - 2) != *(v23 - 2) || *v24 != *v23 )
            {
              v20 = 1;
              if ( !(v21 + v19) )
                goto LABEL_42;
              goto LABEL_35;
            }
            ++v19;
            v23 += 4;
            v24 += 4;
          }
          while ( v21 + v19 != 1 );
          if ( (v20 & 1) != 0 )
          {
LABEL_42:
            *(_QWORD *)(v3 + 5032) = *(_QWORD *)(v4 + 2048);
            v25 = *(_QWORD *)(v4 + 2080);
            v26 = *(_QWORD *)(v4 + 2056);
            v27 = *(_QWORD *)(v4 + 2064);
            *(_QWORD *)(v3 + 5056) = *(_QWORD *)(v4 + 2072);
            *(_QWORD *)(v3 + 5064) = v25;
            *(_QWORD *)(v3 + 5040) = v26;
            *(_QWORD *)(v3 + 5048) = v27;
            v28 = *(_QWORD *)(v4 + 2112);
            v30 = *(_QWORD *)(v4 + 2088);
            v29 = *(_QWORD *)(v4 + 2096);
            *(_QWORD *)(v3 + 5088) = *(_QWORD *)(v4 + 2104);
            *(_QWORD *)(v3 + 5096) = v28;
            *(_QWORD *)(v3 + 5072) = v30;
            *(_QWORD *)(v3 + 5080) = v29;
          }
          else
          {
LABEL_45:
            if ( !v5 )
              goto LABEL_44;
          }
          v31 = 0x6080000010LL;
          result = msm_mode_object_event_notify(v3 + 64, *(_QWORD *)v3, &v31, v3 + 5024);
        }
      }
    }
    else if ( (_drm_debug & 4) != 0 )
    {
      result = _drm_dev_dbg(0, 0, 0, "MISR is disabled\n");
    }
  }
LABEL_44:
  _ReadStatusReg(SP_EL0);
  return result;
}
