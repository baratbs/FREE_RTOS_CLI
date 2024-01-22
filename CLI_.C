#include<string.h>
#include<stdin.h>

#include"FreeRTOS.h"
#include"task.h>

include "FreeRTOS_CLI.h"

typedef struct xCOMMAND_INPUT_LIST
{
    const CLI_command_Definition_t *pxcommandLineDefinition_t *pxCommandLineDefinition;
    struct xCOMMAND_INPUT_LIST *pxNext;
}CLI_Definition_List_Item_t;


static portBASE_TYPE prvHelpCommand(int8_t *pcWriteBuffer, size_t xWriteBufferLen,const int_8t *pcCommandString);

static const CLI_Command_Definiton_t XHelpCommand=
{
    (const int8_t *const) "help",
    (const int8_t *const) "\r\nhelp:\r\n Lists all the registered commands\r\n\r\n",
    prvHelpCommand,
    0
    };

    static CLI_Definition_List_Itme_t xRegisteredCommands=
    {
        &xHelpCommand.
        NULL
    };

    static int8_t cOutputBuffer [configCOMMAND_INT_MAX_OUTPUT_SIZE];

    portBASE_TYPE FreeRTOS_CLIRegisterCommand(const CLI_Command_Definition_t * const pxCommandToRegister)
    {
        static CLI_Definitioin_List_Item_t *pxLasrCommandInList=&xRegisteredCommands;
        CLI_Definition_List_Item_t *pxNewListItem;
        portBASE_TYPE xReturnk=pdFAIL;


        configASSERT (pxCommandToRegidter);

        pxNewListItem=(CLI_Definition_List_Item*)pvPortMalloc(sizeof(CLI_Definition_List_Item_t));
        configASSERT (pxNewListItem);

        if(pxNewListItem !=NULL)
        {
            taskENTER_CRIRICAL();
            {
                pxNwewListItem->pxcommandLineDefintion=pxCommandToRegister;

                pxNewListItem->pxNexr=NULL;

                pxLasrCommandInList->pxNext=pxNewListItem;

                pxLastCommandInList=pxNewListItem;
            }
            taskEXIT_CRITICAL();

            xReturn=pdPASS;
        }
        return xReturn;
    }
