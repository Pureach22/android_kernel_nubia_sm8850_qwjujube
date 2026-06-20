__int64 __fastcall sdam_full_irq_handler(int a1, __int64 a2)
{
  int v3; // w8
  _QWORD *v4; // x9
  __int64 v5; // x25
  __int64 v6; // x20
  int v7; // w0
  unsigned int v8; // w8
  __int64 v9; // x1
  int v10; // w0
  unsigned int v11; // w0
  int v12; // w23
  int v13; // w9
  int v14; // w22
  int v15; // w24
  unsigned int v16; // w0
  __int64 v17; // x26
  __int64 v18; // x0
  unsigned int v19; // w0
  int v20; // w28
  int v21; // w21
  unsigned __int64 v22; // x8
  unsigned __int64 v23; // x27
  __int64 v24; // x24
  int v25; // w26
  __int64 v26; // x8
  int v27; // w0
  __int64 v28; // x0
  __int64 v29; // x9
  __int64 v30; // x8
  __int64 *v31; // x9
  __int64 v32; // x0
  unsigned int v33; // w0
  __int64 v34; // x2
  int v36; // w20
  unsigned __int64 v37; // [xsp+0h] [xbp-30h]
  int v38; // [xsp+10h] [xbp-20h]
  _BYTE v39[4]; // [xsp+14h] [xbp-1Ch] BYREF
  _BYTE v40[4]; // [xsp+18h] [xbp-18h] BYREF
  _BYTE v41[4]; // [xsp+1Ch] [xbp-14h] BYREF
  _BYTE v42[4]; // [xsp+20h] [xbp-10h] BYREF
  unsigned __int16 v43; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v44; // [xsp+28h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_DWORD *)(a2 + 216);
  v42[0] = 0;
  v41[0] = 0;
  v40[0] = 0;
  v39[0] = 0;
  if ( !v3 )
  {
LABEL_5:
    LODWORD(v6) = -2;
LABEL_13:
    dev_err(*(_QWORD *)(a2 + 8), "Invalid SDAM interrupt, err=%d\n", v6);
    goto LABEL_69;
  }
  v4 = *(_QWORD **)(a2 + 40);
  v5 = 0;
  v6 = 0;
  while ( LODWORD(v4[4 * (int)v6 + 3]) != a1 )
  {
    ++v6;
    v5 += 32;
    if ( v3 == (_DWORD)v6 )
      goto LABEL_5;
  }
  if ( (v6 & 0x80000000) != 0 )
    goto LABEL_13;
  v7 = nvmem_device_read(*v4, 80, 1, v41);
  if ( v7 < 0 )
  {
    dev_err(*(_QWORD *)(a2 + 8), "Failed to read interrupt status from SDAM, rc=%d\n", v7);
    goto LABEL_69;
  }
  v8 = *(_DWORD *)(a2 + 36);
  if ( v8 <= 1 )
  {
    if ( (v41[0] & 4) == 0 )
      goto LABEL_20;
    if ( (v8 & 1) != 0 )
    {
      if ( (unsigned int)__ratelimit(&handle_ecm_abort__rs, "handle_ecm_abort") )
        dev_warn(*(_QWORD *)(a2 + 8), "Multiple frames mode is not supported\n");
    }
    else
    {
      if ( *(_DWORD *)(a2 + 24) > 9u )
      {
        v9 = system_wq;
        *(_BYTE *)(a2 + 227) = 1;
        queue_delayed_work_on(32, v9, a2 + 96, 0);
LABEL_19:
        v10 = amoled_ecm_disable(a2);
        if ( v10 < 0 )
        {
          v36 = v10;
          dev_err(*(_QWORD *)(a2 + 8), "Failed to disable AMOLED ECM, rc=%d\n", v10);
          dev_err(*(_QWORD *)(a2 + 8), "Failed to handle ECM_ABORT interrupt, rc=%d\n", v36);
          goto LABEL_69;
        }
LABEL_20:
        if ( (unsigned int)v6 > 2 )
        {
          v34 = 4294967274LL;
        }
        else
        {
          v11 = nvmem_device_read(**(_QWORD **)(a2 + 40), dword_8168[v6], 1, v40);
          if ( (v11 & 0x80000000) == 0 )
          {
            v12 = *(_DWORD *)(*(_QWORD *)(a2 + 40) + v5 + 8);
            if ( *(_BYTE *)(a2 + 225) == 6 )
              v13 = 2;
            else
              v13 = 1;
            v14 = (v40[0] - v12 + 1) / v13;
            v15 = (192 - v12) / v13;
            if ( v14 && v14 <= v15 )
            {
              mutex_lock(a2 + 48);
              v16 = nvmem_device_read(**(_QWORD **)(a2 + 40), 96, 1, v39);
              if ( (v16 & 0x80000000) != 0 )
              {
                dev_err(*(_QWORD *)(a2 + 8), "Failed to read ECM_WRITE_TO_SDAM from SDAM, rc=%d\n", v16);
                goto LABEL_68;
              }
              v17 = 16LL << v6;
              v18 = **(_QWORD **)(a2 + 40);
              v39[0] &= ~(unsigned __int8)(16LL << v6);
              v19 = nvmem_device_write(v18, 96, 1, v39);
              if ( (v19 & 0x80000000) != 0 )
                goto LABEL_60;
              v20 = *(unsigned __int8 *)(a2 + 225);
              v21 = v40[0];
              if ( v20 == 7 )
              {
                v22 = 50;
                if ( v12 < v40[0] )
                {
LABEL_34:
                  v37 = v22;
                  v38 = v15;
                  v23 = 0;
                  if ( v20 == 6 )
                    v24 = 2;
                  else
                    v24 = 1;
                  if ( v20 == 6 )
                    v25 = 2;
                  else
                    v25 = 1;
                  v43 = 0;
                  do
                  {
                    v27 = nvmem_device_read(*(_QWORD *)(*(_QWORD *)(a2 + 40) + v5), (unsigned int)v12, v24, &v43);
                    if ( v27 <= 0 )
                    {
                      dev_err(*(_QWORD *)(a2 + 8), "Failed to read SDAM sample, rc=%d\n", v27);
                      v15 = v38;
                      LOBYTE(v17) = 16LL << v6;
                      v23 = 0;
                      goto LABEL_53;
                    }
                    if ( v20 == 6 )
                      v26 = v43;
                    else
                      v26 = (unsigned __int8)v43;
                    v12 += v25;
                    v23 += v26;
                  }
                  while ( v12 < v21 );
                  v22 = v37;
                  LOBYTE(v17) = 16LL << v6;
                  v20 = *(unsigned __int8 *)(a2 + 225);
                  v15 = v38;
                  if ( v20 != 7 )
                    goto LABEL_48;
                  goto LABEL_52;
                }
              }
              else
              {
                if ( v20 != 6 )
                {
                  v23 = 0;
                  goto LABEL_53;
                }
                v22 = 15;
                if ( *(_BYTE *)(a2 + 224) )
                  v22 = 16;
                if ( v12 < v40[0] )
                  goto LABEL_34;
              }
              v23 = 0;
              if ( v20 != 7 )
              {
LABEL_48:
                if ( v20 == 6 )
                  v23 = 1000 * v23 / v22 / 0x3E8;
LABEL_53:
                v28 = **(_QWORD **)(a2 + 40);
                v39[0] |= v17;
                v19 = nvmem_device_write(v28, 96, 1, v39);
                if ( (v19 & 0x80000000) == 0 )
                {
                  if ( v23 )
                  {
                    v29 = *(_QWORD *)(a2 + 16);
                    ++*(_DWORD *)(a2 + 24);
                    v30 = v29 + v23 / v14;
                    v31 = *(__int64 **)(a2 + 40);
                    *(_QWORD *)(a2 + 16) = v30;
                    v32 = *v31;
                    v42[0] = 8LL << v6;
                    v33 = nvmem_device_write(v32, 81, 1, v42);
                    if ( (v33 & 0x80000000) != 0 )
                    {
                      dev_err(*(_QWORD *)(a2 + 8), "Failed to clear interrupt status in SDAM, rc=%d\n", v33);
                    }
                    else if ( *(_DWORD *)(a2 + 36) == 1 && v15 > v40[0] )
                    {
                      queue_delayed_work_on(32, system_wq, a2 + 96, 0);
                    }
                  }
                  else
                  {
                    dev_err(*(_QWORD *)(a2 + 8), "Error, No ECM samples captured. Cumulative:%llu\n", 0);
                  }
                  goto LABEL_68;
                }
LABEL_60:
                dev_err(*(_QWORD *)(a2 + 8), "Failed to write ECM_WRITE_TO_SDAM to SDAM, rc=%d\n", v19);
LABEL_68:
                mutex_unlock(a2 + 48);
                goto LABEL_69;
              }
LABEL_52:
              v23 *= v22;
              goto LABEL_53;
            }
            dev_err(
              *(_QWORD *)(a2 + 8),
              "Incorrect number of ECM samples, num_ecm_samples:%d max_samples:%d\n",
              v14,
              v15);
            goto LABEL_69;
          }
          v34 = v11;
        }
        dev_err(*(_QWORD *)(a2 + 8), "Failed to read SDAM index, rc=%d\n", v34);
        goto LABEL_68;
      }
      if ( (unsigned int)__ratelimit(&handle_ecm_abort__rs_32, "handle_ecm_abort") )
        dev_warn(*(_QWORD *)(a2 + 8), "Too few samples %u for continuous mode\n", *(_DWORD *)(a2 + 24));
    }
    *(_WORD *)(a2 + 34) = 0;
    goto LABEL_19;
  }
LABEL_69:
  _ReadStatusReg(SP_EL0);
  return 1;
}
