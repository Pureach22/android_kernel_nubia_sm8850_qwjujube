__int64 __fastcall msm_channel_map_get(__int64 a1, __int64 a2)
{
  unsigned int v2; // w23
  unsigned int *v3; // x24
  __int64 v5; // x2
  _QWORD *v6; // x25
  unsigned __int64 v7; // x8
  size_t v8; // x20
  __int64 v9; // x21
  _QWORD *v10; // x22
  __int64 v11; // x26
  __int64 v12; // x0
  unsigned int channel_map; // w0
  unsigned int v14; // w19
  __int64 result; // x0
  unsigned int *v16; // x0
  __int64 v17; // x8
  unsigned __int64 v18; // x8
  unsigned __int64 v19; // x9
  unsigned int *v20; // x0
  unsigned int v21; // w24
  unsigned int v22; // w8
  unsigned int v23; // w9
  unsigned __int64 v24; // x9
  unsigned __int64 v25; // x12
  _DWORD *v26; // x8
  __int64 v27; // x11
  int *v28; // x10
  unsigned __int64 v29; // x11
  int v30; // w12
  int v31; // w13
  unsigned __int64 v32; // x8
  __int64 v33; // x9
  unsigned __int64 v34; // x10
  bool v35; // cf
  unsigned int *v36; // x8
  void *v37; // x0
  unsigned int *v38; // x19
  unsigned __int64 StatusReg; // x24
  __int64 v40; // x25
  __int64 (__fastcall *v41)(_QWORD, _QWORD, _QWORD, _QWORD); // x0
  __int64 v42; // [xsp+0h] [xbp-C0h] BYREF
  __int64 v43; // [xsp+8h] [xbp-B8h] BYREF
  unsigned __int64 v44; // [xsp+10h] [xbp-B0h] BYREF
  _QWORD v45[10]; // [xsp+18h] [xbp-A8h] BYREF
  _QWORD v46[11]; // [xsp+68h] [xbp-58h] BYREF

  v46[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(unsigned int **)(a1 + 128);
  memset(v46, 0, 80);
  memset(v45, 0, sizeof(v45));
  v44 = 0;
  if ( v3 )
  {
    v6 = v3 + 2;
    v5 = *v3;
    if ( (_DWORD)v5 != 1 )
    {
      if ( (_DWORD)v5 == 2 )
      {
        v7 = v3[1];
        v8 = 0;
        LODWORD(v9) = 0;
        LODWORD(v10) = 0;
        v2 = 0;
        v42 = 0;
        v43 = 0;
        if ( (_DWORD)v7 )
        {
          v11 = 0;
          while ( v11 != 8 )
          {
            v12 = v6[v11];
            if ( v12 )
            {
              v42 = 0;
              v43 = 0;
              channel_map = snd_soc_dai_get_channel_map(v12, &v42, &v43, (char *)&v42 + 4, (char *)&v43 + 4);
              if ( channel_map != -524 && channel_map )
              {
                v14 = channel_map;
                printk(&unk_14140, "msm_channel_map_get", 2);
                result = v14;
                goto LABEL_62;
              }
              v2 += HIDWORD(v42);
              v7 = v3[1];
              LODWORD(v10) = (_DWORD)v10 + v42;
              LODWORD(v9) = v9 | HIDWORD(v43);
              v8 = (unsigned int)v8 | (unsigned int)v43;
              v44 = __PAIR64__(v2, (unsigned int)v10);
              LODWORD(v46[0]) = v9;
              LODWORD(v45[0]) = v8;
            }
            if ( ++v11 >= v7 )
              goto LABEL_33;
          }
          __break(0x5512u);
          goto LABEL_60;
        }
LABEL_33:
        if ( !(v2 | (unsigned int)v10) )
          goto LABEL_34;
        v20 = (unsigned int *)_kmalloc_cache_noprof(kobject_init_and_add, 3520, 8);
        if ( v20 )
        {
LABEL_36:
          v21 = 0;
          if ( v2 )
            v22 = v2;
          else
            v22 = (unsigned int)v10;
          if ( v2 )
            v23 = v9;
          else
            v23 = v8;
          *v20 = v22;
          v20[1] = v23;
          *(_QWORD *)(a2 + 72) = *(_QWORD *)v20;
          goto LABEL_57;
        }
        goto LABEL_61;
      }
      printk(&unk_136FA, "msm_channel_map_get", v5);
      v20 = nullptr;
      v21 = -22;
      goto LABEL_57;
    }
    result = snd_soc_dai_get_channel_map(*v6, &v44, v45, (char *)&v44 + 4, v46);
    if ( !(_DWORD)result )
    {
      if ( !v44 )
      {
LABEL_34:
        result = 0;
        goto LABEL_62;
      }
      if ( HIDWORD(v44) )
        v9 = HIDWORD(v44);
      else
        v9 = (unsigned int)v44;
      if ( HIDWORD(v44) )
        v10 = v46;
      else
        v10 = v45;
      if ( (unsigned int)v9 >= 3 )
      {
        printk(&unk_13DDC, "msm_channel_map_get", (unsigned int)v9);
        result = 4294967274LL;
        goto LABEL_62;
      }
      v8 = (unsigned int)(4 * v9 + 4);
      v16 = (unsigned int *)_kmalloc_noprof(v8, 3520);
      if ( !v16 )
      {
LABEL_61:
        result = 4294967284LL;
        goto LABEL_62;
      }
      *v16 = v9;
      if ( (_DWORD)v9 )
      {
        v17 = 3 - v8;
        if ( v8 == 7 || 3 - v8 < 0xFFFFFFFFFFFFFFFCLL )
          v17 = -4;
        v18 = (v17 + v8) >> 2;
        if ( v8 >> 2 < v18 )
          v18 = v8 >> 2;
        if ( v18 >= v9 - 1 )
          v18 = v9 - 1;
        if ( v18 >= 2 )
        {
          if ( v18 >= 0x14 )
            v18 = 20;
          v24 = v18 + 1;
          v25 = ~v18;
          v26 = v16 + 2;
          v27 = v24 & 1;
          if ( (v24 & 1) == 0 )
            v27 = 2;
          v28 = (int *)v10 + 1;
          v19 = v24 - v27;
          v29 = v25 + v27;
          do
          {
            v30 = *(v28 - 1);
            v31 = *v28;
            v29 += 2LL;
            v28 += 2;
            *(v26 - 1) = v30;
            *v26 = v31;
            v26 += 2;
          }
          while ( v29 );
        }
        else
        {
          v19 = 0;
        }
        v32 = 4 * v19;
        v33 = v9 - v19;
        v34 = v8 - v32 - 4;
        while ( v32 <= 0x4F )
        {
          if ( v8 < v32 + 4 )
            break;
          v35 = v34 >= 4;
          v34 -= 4LL;
          if ( !v35 )
            break;
          --v33;
          v16[v32 / 4 + 1] = *(_DWORD *)((char *)v10 + v32);
          v32 += 4LL;
          if ( !v33 )
            goto LABEL_56;
        }
LABEL_60:
        __break(1u);
        _fortify_panic(16, -1, v8);
        StatusReg = _ReadStatusReg(SP_EL0);
        v40 = *(_QWORD *)(StatusReg + 80);
        v41 = kobject_init_and_add;
        *(_QWORD *)(StatusReg + 80) = &msm_channel_map_get__alloc_tag_46;
        v20 = (unsigned int *)_kmalloc_cache_noprof(v41, 3520, 8);
        *(_QWORD *)(StatusReg + 80) = v40;
        if ( !v20 )
          goto LABEL_61;
        goto LABEL_36;
      }
LABEL_56:
      v36 = v16;
      v37 = (void *)(a2 + 72);
      v38 = v36;
      memcpy(v37, v36, v8);
      v20 = v38;
      v21 = 0;
LABEL_57:
      kfree(v20);
      result = v21;
    }
  }
  else
  {
    result = 4294967274LL;
  }
LABEL_62:
  _ReadStatusReg(SP_EL0);
  return result;
}
