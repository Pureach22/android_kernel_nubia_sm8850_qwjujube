unsigned int *__fastcall update_sysmon_smem_pointers(unsigned int *result, int a2, unsigned __int64 a3)
{
  unsigned __int64 v3; // x8
  unsigned __int64 v4; // x19
  unsigned int *v5; // x21
  unsigned __int64 v6; // x22
  _QWORD *v8; // x11
  _QWORD *v9; // x12
  _QWORD *v10; // x13
  _QWORD *v11; // x14
  unsigned int v12; // w3
  unsigned __int64 v13; // x8
  _QWORD *v14; // x27
  _QWORD *v15; // x24
  _QWORD *v16; // x23
  void *v17; // x0
  _QWORD *v18; // x23
  void *v19; // x0

  if ( a3 )
  {
    v3 = *result;
    v4 = a3;
    v5 = result;
    v6 = (v3 >> 16) & 0xFFF;
    if ( v6 <= a3 )
    {
      v8 = &loc_9000;
      v9 = &loc_9000;
      v10 = &loc_9000;
      v11 = &loc_9000;
      result = (unsigned int *)&loc_9000;
      while ( 1 )
      {
        v12 = (unsigned int)v3 >> 28;
        if ( (unsigned int)v3 >> 28 > 3 )
        {
          switch ( v12 )
          {
            case 4u:
              if ( v5 == (unsigned int *)-4LL || (unsigned __int64)(v5 + 1) > 0xFFFFFFFFFFFFF000LL )
                return (unsigned int *)printk(&unk_9EB6, "sysmon_subsystem_stats");
              if ( a2 != 5 )
              {
                v17 = &unk_A24D;
                goto LABEL_63;
              }
              qword_96A8 = (__int64)(v5 + 1);
              v5 = (unsigned int *)((char *)v5 + v6);
              if ( !v5 )
                return result;
              break;
            case 5u:
              if ( v5 == (unsigned int *)-4LL || (unsigned __int64)(v5 + 1) > 0xFFFFFFFFFFFFF000LL )
                return (unsigned int *)printk(&unk_9EB6, "sysmon_subsystem_stats");
              if ( a2 != 5 )
              {
                v17 = &unk_A24D;
                goto LABEL_63;
              }
              qword_96B0 = (__int64)(v5 + 1);
              v5 = (unsigned int *)((char *)v5 + v6);
              if ( !v5 )
                return result;
              break;
            case 8u:
              if ( !v5 || (unsigned __int64)v5 > 0xFFFFFFFFFFFFF000LL )
                return (unsigned int *)printk(&unk_9EB6, "sysmon_subsystem_stats");
              if ( a2 != 5 )
              {
                v17 = &unk_A820;
LABEL_63:
                v14 = v8;
                v15 = v9;
                v18 = v11;
                printk(v17, "sysmon_subsystem_stats");
                result = (unsigned int *)&loc_9000;
                v11 = v18;
                v10 = &loc_9000;
LABEL_64:
                v9 = v15;
                v8 = v14;
                v5 = (unsigned int *)((char *)v5 + v6);
                if ( !v5 )
                  return result;
                break;
              }
              qword_9638 = (__int64)v5;
              v5 = (unsigned int *)((char *)v5 + v6);
              if ( !v5 )
                return result;
              break;
            default:
LABEL_59:
              v14 = v8;
              v15 = v9;
              v16 = v10;
              printk(&unk_A14C, "sysmon_subsystem_stats");
              result = (unsigned int *)&loc_9000;
              v11 = &loc_9000;
              v10 = v16;
              goto LABEL_64;
          }
        }
        else
        {
          switch ( v12 )
          {
            case 1u:
              v13 = (unsigned __int64)(v5 + 1);
              if ( v5 == (unsigned int *)-4LL || v13 > 0xFFFFFFFFFFFFF000LL )
                return (unsigned int *)printk(&unk_9EB6, "sysmon_subsystem_stats");
              switch ( a2 )
              {
                case 5:
                  qword_9670 = (__int64)(v5 + 1);
                  v5 = (unsigned int *)((char *)v5 + v6);
                  if ( !v5 )
                    return result;
                  break;
                case 3:
                  qword_9678 = (__int64)(v5 + 1);
                  v5 = (unsigned int *)((char *)v5 + v6);
                  if ( !v5 )
                    return result;
                  break;
                case 2:
                  v8[205] = v13;
                  v5 = (unsigned int *)((char *)v5 + v6);
                  if ( !v5 )
                    return result;
                  break;
                default:
                  v19 = &unk_9CA4;
                  goto LABEL_69;
              }
              break;
            case 2u:
              if ( v5 == (unsigned int *)-4LL || (unsigned __int64)(v5 + 1) > 0xFFFFFFFFFFFFF000LL )
                return (unsigned int *)printk(&unk_9EB6, "sysmon_subsystem_stats");
              switch ( a2 )
              {
                case 5:
                  qword_9628 = (__int64)v5;
                  v5 = (unsigned int *)((char *)v5 + v6);
                  if ( !v5 )
                    return result;
                  break;
                case 3:
                  qword_9630 = (__int64)v5;
                  v5 = (unsigned int *)((char *)v5 + v6);
                  if ( !v5 )
                    return result;
                  break;
                case 2:
                  v9[196] = v5;
                  v5 = (unsigned int *)((char *)v5 + v6);
                  if ( !v5 )
                    return result;
                  break;
                default:
                  v19 = &unk_9CA4;
                  goto LABEL_69;
              }
              break;
            case 3u:
              if ( v5 == (unsigned int *)-4LL || (unsigned __int64)(v5 + 1) > 0xFFFFFFFFFFFFF000LL )
                return (unsigned int *)printk(&unk_9EB6, "sysmon_subsystem_stats");
              switch ( a2 )
              {
                case 5:
                  v10[194] = v5;
                  v5 = (unsigned int *)((char *)v5 + v6);
                  if ( !v5 )
                    return result;
                  break;
                case 3:
                  v11[195] = v5;
                  v5 = (unsigned int *)((char *)v5 + v6);
                  if ( !v5 )
                    return result;
                  break;
                case 2:
                  qword_9608 = (__int64)v5;
                  v5 = (unsigned int *)((char *)v5 + v6);
                  if ( !v5 )
                    return result;
                  break;
                default:
                  v19 = &unk_9DA1;
LABEL_69:
                  printk(v19, "sysmon_subsystem_stats");
                  result = (unsigned int *)&loc_9000;
                  v11 = &loc_9000;
                  v10 = &loc_9000;
                  v9 = &loc_9000;
                  v8 = &loc_9000;
                  v5 = (unsigned int *)((char *)v5 + v6);
                  if ( !v5 )
                    return result;
                  goto LABEL_70;
              }
              break;
            default:
              goto LABEL_59;
          }
        }
LABEL_70:
        if ( (unsigned __int64)v5 <= 0xFFFFFFFFFFFFF000LL && v4 > v6 )
        {
          v4 -= v6;
          if ( v4 )
          {
            v3 = *v5;
            v6 = (v3 >> 16) & 0xFFF;
            if ( v4 >= v6 )
              continue;
          }
        }
        return result;
      }
    }
  }
  return result;
}
