__int64 __fastcall kgsl_drawobj_add_timeline(__int64 *a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v6; // x20
  __int64 result; // x0
  __int64 v9; // x0
  __int64 v10; // x23
  __int64 v11; // x1
  __int64 v12; // x2
  unsigned __int64 v13; // x8
  signed int v14; // w25
  size_t v15; // x24
  __int64 v16; // x9
  __int64 v17; // x0
  __int64 v18; // x24
  __int64 v19; // x8
  __int64 v20; // x9
  int v21; // w8
  unsigned int v22; // w8
  unsigned int v23; // w28
  unsigned int v29; // w9
  unsigned int v30; // w10
  int v31; // w9
  __int64 v32; // x1
  __int64 v33; // x2
  int v34; // w20
  unsigned int v35; // w20
  signed int v36; // w24
  unsigned __int64 v37; // x8
  int v40; // w8
  int v43; // w8
  __int64 v44; // [xsp+10h] [xbp-30h] BYREF
  __int64 v45; // [xsp+18h] [xbp-28h]
  unsigned int v46; // [xsp+24h] [xbp-1Ch]
  __int64 v47; // [xsp+28h] [xbp-18h] BYREF
  __int64 v48; // [xsp+30h] [xbp-10h]
  __int64 v49; // [xsp+38h] [xbp-8h]

  v49 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *a1;
  _X21 = *(unsigned int **)(a2 + 8);
  v46 = 0;
  v47 = 0;
  v48 = 0;
  result = get_aux_command(a3, a4, 2, &v47, 16);
  if ( !(_DWORD)result )
  {
    if ( (_DWORD)v48 )
    {
      v9 = _kvmalloc_node_noprof(48LL * (unsigned int)v48, 0, 77248, 0xFFFFFFFFLL);
      *(_QWORD *)(a2 + 64) = v9;
      if ( v9 )
      {
        v10 = v47;
        result = kgsl_readtimestamp(v6);
        if ( !(_DWORD)result )
        {
          if ( (_DWORD)v48 )
          {
            v13 = HIDWORD(v48);
            v14 = 0;
            _ReadStatusReg(SP_EL0);
            while ( 1 )
            {
              v44 = 0;
              v45 = 0;
              if ( v13 >= 0x10 )
                v15 = 16;
              else
                v15 = v13;
              if ( v13 <= 0x10 )
                v16 = 16;
              else
                v16 = v13;
              if ( v13 > 0xF )
              {
                if ( v13 != 16 && (int)check_zeroed_user(v10 + v15, v16 - v15) < 1 )
                {
LABEL_43:
                  v21 = -14;
                  goto LABEL_46;
                }
              }
              else
              {
                memset((char *)&v44 + v15, 0, v16 - v15);
              }
              _check_object_size(&v44, v15, 0);
              if ( inline_copy_from_user_1((int)&v44, v10, v15) )
                goto LABEL_43;
              if ( HIDWORD(v45) )
              {
                v21 = -22;
                goto LABEL_46;
              }
              v17 = kgsl_timeline_by_id(*a1, (unsigned int)v45);
              v18 = v14;
              v19 = 48LL * v14;
              *(_QWORD *)(*(_QWORD *)(a2 + 64) + v19) = v17;
              v20 = *(_QWORD *)(*(_QWORD *)(a2 + 64) + v19);
              v21 = -19;
              if ( !v20 || !_X21 )
                goto LABEL_46;
              v22 = *_X21;
              if ( *_X21 )
              {
                do
                {
                  __asm { PRFM            #0x11, [X21] }
                  do
                    v29 = __ldxr(_X21);
                  while ( v29 == v22 && __stxr(v22 + 1, _X21) );
                  v23 = v22;
                  if ( v29 == v22 )
                    break;
                  v23 = 0;
                  v22 = v29;
                }
                while ( v29 );
              }
              else
              {
                v23 = 0;
              }
              if ( (((v23 + 1) | v23) & 0x80000000) != 0 )
              {
                refcount_warn_saturate(_X21, 0);
                if ( !v23 )
                {
LABEL_45:
                  v21 = -19;
                  goto LABEL_46;
                }
              }
              else if ( !v23 )
              {
                goto LABEL_45;
              }
              v11 = (unsigned int)v45;
              v12 = v44;
              ++v14;
              *(_QWORD *)(*(_QWORD *)(a2 + 64) + 48 * v18 + 8) = v44;
              v30 = v46;
              *(_QWORD *)(*(_QWORD *)(a2 + 64) + 48 * v18 + 16) = _X21;
              *(_DWORD *)(*(_QWORD *)(a2 + 64) + 48 * v18 + 24) = v30;
              v31 = v48;
              v13 = HIDWORD(v48);
              v10 += HIDWORD(v48);
              if ( v14 >= (unsigned int)v48 )
                goto LABEL_39;
            }
          }
          v31 = 0;
LABEL_39:
          *(_DWORD *)(a2 + 72) = v31;
          kref_get_0(a2 + 32, v11, v12);
          kref_get_0(a2 + 56, v32, v33);
          result = kgsl_add_event(v6, _X21 + 16, v46, timeline_signaled, a2);
          if ( (_DWORD)result )
          {
            v34 = result;
            kref_put(a2 + 56, drawobj_timelineobj_retire);
            if ( a2 )
              kref_put(a2 + 32, kgsl_drawobj_destroy_object);
            v21 = v34;
LABEL_46:
            v35 = v21;
            if ( (_DWORD)v48 )
            {
              v36 = 0;
              do
              {
                v37 = *(_QWORD *)(*(_QWORD *)(a2 + 64) + 48LL * v36);
                if ( v37 && v37 <= 0xFFFFFFFFFFFFF000LL )
                {
                  _X0 = (unsigned int *)(v37 + 32);
                  __asm { PRFM            #0x11, [X0] }
                  do
                    v40 = __ldxr(_X0);
                  while ( __stlxr(v40 - 1, _X0) );
                  if ( v40 == 1 )
                  {
                    __dmb(9u);
                    kgsl_timeline_destroy();
                  }
                  else if ( v40 <= 0 )
                  {
                    refcount_warn_saturate(_X0, 3);
                  }
                }
                _X0 = *(unsigned int **)(*(_QWORD *)(a2 + 64) + 48LL * v36 + 16);
                if ( _X0 )
                {
                  __asm { PRFM            #0x11, [X0] }
                  do
                    v43 = __ldxr(_X0);
                  while ( __stlxr(v43 - 1, _X0) );
                  if ( v43 == 1 )
                  {
                    __dmb(9u);
                    kgsl_context_destroy((__int64)_X0);
                  }
                  else if ( v43 <= 0 )
                  {
                    refcount_warn_saturate(_X0, 3);
                  }
                }
                ++v36;
              }
              while ( v36 < (unsigned int)v48 );
            }
            kvfree(*(_QWORD *)(a2 + 64));
            result = v35;
            *(_QWORD *)(a2 + 64) = 0;
          }
        }
      }
      else
      {
        result = 4294967284LL;
      }
    }
    else
    {
      result = 4294967274LL;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
