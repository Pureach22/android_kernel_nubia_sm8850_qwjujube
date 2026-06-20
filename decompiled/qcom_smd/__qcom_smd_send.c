__int64 __fastcall _qcom_smd_send(__int64 *a1, __int64 a2, int a3, char a4)
{
  int v7; // w25
  __int64 v9; // x23
  __int64 v10; // x1
  _DWORD *v11; // x8
  _DWORD *v12; // x10
  _DWORD *v13; // x11
  __int64 v14; // x11
  int v15; // w9
  __int64 v16; // x10
  _DWORD *v17; // x9
  _DWORD *v18; // x10
  __int64 v19; // x10
  __int64 result; // x0
  __int64 v21; // x10
  _DWORD *v22; // x9
  _DWORD *v23; // x10
  __int64 v24; // x10
  __int64 v25; // x0
  __int64 v26; // x8
  __int64 v27; // x26
  unsigned int *v28; // x8
  __int64 v29; // x20
  __int64 v30; // x25
  int v31; // w8
  __int64 v32; // x23
  unsigned __int64 v33; // x22
  unsigned int v34; // w27
  __int64 v35; // x8
  __int64 v36; // x0
  char *v37; // x1
  unsigned __int64 v38; // x2
  __int64 v39; // x9
  _DWORD *v40; // x9
  __int64 v41; // x26
  unsigned int *v42; // x8
  __int64 v43; // x25
  int v44; // w8
  unsigned __int64 v45; // x27
  unsigned __int64 v46; // x22
  __int64 v47; // x8
  __int64 v48; // x0
  __int64 v49; // x1
  unsigned __int64 v50; // x2
  __int64 v51; // x9
  _DWORD *v52; // x9
  __int64 v53; // x8
  __int64 v54; // x20
  __int64 v55; // x0
  _QWORD v56[5]; // [xsp+8h] [xbp-48h] BYREF
  int v57; // [xsp+34h] [xbp-1Ch] BYREF
  __int64 v58; // [xsp+38h] [xbp-18h]
  __int64 v59; // [xsp+40h] [xbp-10h]
  __int64 v60; // [xsp+48h] [xbp-8h]

  v60 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v58 = 0;
  v59 = 0;
  v57 = a3;
  if ( (a3 & 3) != 0 && a1[9] || (v7 = a3 + 20, a3 + 20 >= *((_DWORD *)a1 + 32)) )
  {
    result = 4294967274LL;
    goto LABEL_87;
  }
  v9 = raw_spin_lock_irqsave(a1 + 10);
  v10 = v9;
  while ( 1 )
  {
    v11 = (_DWORD *)a1[9];
    if ( v11 )
    {
      v12 = v11 + 10;
      v13 = v11 + 9;
    }
    else
    {
      v14 = a1[8];
      v12 = (_DWORD *)(v14 + 16);
      v13 = (_DWORD *)(v14 + 12);
    }
    v15 = *((_DWORD *)a1 + 8);
    if ( ((*v13 + ~*v12) & (unsigned int)(*((_DWORD *)a1 + 32) - 1)) >= (unsigned __int64)v7 )
    {
      if ( v15 != 2 )
      {
        v29 = 4294967264LL;
        goto LABEL_86;
      }
      if ( v11 )
      {
        v11[6] = 0;
        v27 = a1[9];
        if ( v27 )
        {
LABEL_36:
          v28 = (unsigned int *)(v27 + 40);
          goto LABEL_46;
        }
      }
      else
      {
        *(_BYTE *)(a1[8] + 9) = 0;
        v27 = a1[9];
        if ( v27 )
          goto LABEL_36;
      }
      v28 = (unsigned int *)(a1[8] + 16);
LABEL_46:
      v30 = *v28;
      v31 = *((_DWORD *)a1 + 32);
      v32 = v10;
      if ( (unsigned int)(v31 - v30) >= 0x14 )
        v33 = 20;
      else
        v33 = (unsigned int)(v31 - v30);
      v34 = v31 - v30;
      if ( v31 != (_DWORD)v30 )
      {
        v35 = a1[14];
        if ( !v27 )
        {
          _memcpy_toio(v35 + v30, &v57, v33);
          if ( v34 > 0x13 )
            goto LABEL_58;
          v36 = a1[14];
          v37 = (char *)&v57 + v33;
          v38 = 20 - v33;
LABEL_57:
          _memcpy_toio(v36, v37, v38);
LABEL_58:
          v39 = a1[9];
          if ( v39 )
            v40 = (_DWORD *)(v39 + 40);
          else
            v40 = (_DWORD *)(a1[8] + 16);
          *v40 = (*((_DWORD *)a1 + 32) - 1) & (v30 + 20);
          v41 = a1[9];
          if ( v41 )
            v42 = (unsigned int *)(v41 + 40);
          else
            v42 = (unsigned int *)(a1[8] + 16);
          v43 = *v42;
          v44 = *((_DWORD *)a1 + 32);
          v45 = (unsigned int)(v44 - v43);
          if ( v45 >= a3 )
            v46 = a3;
          else
            v46 = (unsigned int)(v44 - v43);
          if ( v46 )
          {
            v47 = a1[14];
            if ( !v41 )
            {
              _memcpy_toio(v47 + v43, a2, v46);
              if ( v45 >= a3 )
                goto LABEL_76;
              v48 = a1[14];
              v49 = a2 + v46;
              v50 = a3 - v46;
              goto LABEL_75;
            }
            _iowrite32_copy_full(v47 + v43, a2, v46 >> 2);
          }
          if ( v45 >= a3 )
          {
LABEL_76:
            v51 = a1[9];
            if ( v51 )
              v52 = (_DWORD *)(v51 + 40);
            else
              v52 = (_DWORD *)(a1[8] + 16);
            *v52 = (*((_DWORD *)a1 + 32) - 1) & (v43 + a3);
            v53 = a1[9];
            if ( v53 )
              *(_DWORD *)(v53 + 20) = 1;
            else
              *(_BYTE *)(a1[8] + 8) = 1;
            __dsb(0xEu);
            v54 = *a1;
            v55 = *(_QWORD *)(*a1 + 1016);
            if ( v55 )
            {
              mbox_send_message(v55, 0);
              mbox_client_txdone(*(_QWORD *)(v54 + 1016), 0);
            }
            else
            {
              regmap_write(*(_QWORD *)(v54 + 944), *(unsigned int *)(v54 + 952), 1LL << *(_DWORD *)(v54 + 956));
            }
            v29 = 0;
            v10 = v32;
            goto LABEL_86;
          }
          v48 = a1[14];
          v49 = a2 + v46;
          v50 = a3 - v46;
          if ( v41 )
          {
            _iowrite32_copy_full(v48, v49, v50 >> 2);
            goto LABEL_76;
          }
LABEL_75:
          _memcpy_toio(v48, v49, v50);
          goto LABEL_76;
        }
        _iowrite32_copy_full(v35 + v30, &v57, v33 >> 2);
      }
      if ( v34 >= 0x14 )
        goto LABEL_58;
      v36 = a1[14];
      v37 = (char *)&v57 + v33;
      v38 = 20 - v33;
      if ( v27 )
      {
        _iowrite32_copy_full(v36, v37, v38 >> 2);
        goto LABEL_58;
      }
      goto LABEL_57;
    }
    if ( v15 != 2 || (a4 & 1) == 0 )
      break;
    if ( v11 )
      v11[8] = 0;
    else
      *(_BYTE *)(a1[8] + 11) = 0;
    raw_spin_unlock_irqrestore(a1 + 10, v10);
    v16 = a1[9];
    if ( v16 )
    {
      v17 = (_DWORD *)(v16 + 40);
      v18 = (_DWORD *)(v16 + 36);
    }
    else
    {
      v19 = a1[8];
      v17 = (_DWORD *)(v19 + 16);
      v18 = (_DWORD *)(v19 + 12);
    }
    if ( ((*v18 + ~*v17) & (unsigned int)(*((_DWORD *)a1 + 32) - 1)) < (unsigned __int64)v7 && *((_DWORD *)a1 + 8) == 2 )
    {
      memset(v56, 0, sizeof(v56));
      init_wait_entry(v56, 0);
      while ( 1 )
      {
        result = prepare_to_wait_event(a1 + 11, v56, 1);
        v21 = a1[9];
        if ( v21 )
        {
          v22 = (_DWORD *)(v21 + 40);
          v23 = (_DWORD *)(v21 + 36);
        }
        else
        {
          v24 = a1[8];
          v22 = (_DWORD *)(v24 + 16);
          v23 = (_DWORD *)(v24 + 12);
        }
        if ( ((*v23 + ~*v22) & (unsigned int)(*((_DWORD *)a1 + 32) - 1)) >= (unsigned __int64)v7
          || *((_DWORD *)a1 + 8) != 2 )
        {
          finish_wait(a1 + 11, v56);
          goto LABEL_30;
        }
        if ( result )
          break;
        schedule();
      }
      if ( (_DWORD)result )
        goto LABEL_87;
    }
LABEL_30:
    v25 = raw_spin_lock_irqsave(a1 + 10);
    v26 = a1[9];
    v10 = v25;
    if ( v26 )
      *(_DWORD *)(v26 + 32) = 1;
    else
      *(_BYTE *)(a1[8] + 11) = 1;
  }
  if ( v15 == 2 )
    v29 = 4294967285LL;
  else
    v29 = 4294967264LL;
  if ( v15 == 2 )
    v10 = v9;
LABEL_86:
  raw_spin_unlock_irqrestore(a1 + 10, v10);
  result = v29;
LABEL_87:
  _ReadStatusReg(SP_EL0);
  return result;
}
